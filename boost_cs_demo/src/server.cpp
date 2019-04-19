#include "boost_cs_demo/server.h"

Server::Server() : m_acceptor(m_io, endpoint(ip::tcp::v4(), 8002)), count(0)
{
  accept();
}

void Server::run()
{
  m_io.run();
}

void Server::accept()
{
  socket_ptr sock(new ip::tcp::socket(m_io));
  m_acceptor.async_accept(*sock, bind(&Server::accept_handler, this, boost::asio::placeholders::error, sock));
}

void Server::accept_handler(const boost::system::error_code& ec, socket_ptr sock)
{
  if (ec)return;
  cout << "client:" << endl;
  cout << sock->remote_endpoint().address() << endl;
  sock->async_write_some(buffer(boost::lexical_cast<std::string>(++count)), bind(&Server::write_handler, this, boost::asio::placeholders::error, sock));
  accept();
}

void Server::write_handler(const boost::system::error_code& ec, socket_ptr sock)
{
  if (ec)return;
  sock->async_read_some(buffer(m_buffer, 100), bind(&Server::read_handler, this, boost::asio::placeholders::error, sock));
}

void Server::read_handler(const boost::system::error_code& ec, socket_ptr sock)
{
  if (ec)return;
  cout << "read something:" << m_buffer << endl;
  cout << "ready to write again" << endl;
  sock->async_write_some(buffer(boost::lexical_cast<std::string>(++count)), bind(&Server::write_handler, this, boost::asio::placeholders::error, sock));
}
