#include "boost_cs_demo/client.h"

Client::Client() : m_ep(ip::address::from_string("127.0.0.1"), 8002)
{
  start();
}

void Client::run()
{
  m_io.run();
}

void Client::start()
{
  socket_ptr sock(new ip::tcp::socket(m_io));
  sock->async_connect(m_ep, bind(&Client::conn_handler, this, boost::asio::placeholders::error, sock));
}

void Client::conn_handler(const boost::system::error_code& ec, socket_ptr sock)
{
  if (ec) return;
  cout << "receive from" << sock->remote_endpoint().address() << endl;
  sock->async_read_some(buffer(m_buffer, 100), bind(&Client::read_handler, this, boost::asio::placeholders::error, sock));
}

void Client::read_handler(const boost::system::error_code& ec, socket_ptr sock)
{
  std::string a = "hello";
  auto b = std::make_shared<std::string>(a);
  cout << "get:" << m_buffer << endl;
  sock->async_write_some(buffer(*b), bind(&Client::conn_handler, this, boost::asio::placeholders::error, sock));
}
