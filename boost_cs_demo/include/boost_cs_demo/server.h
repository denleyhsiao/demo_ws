#ifndef __BOOST_CS_DEMO_SERVER_H__
#define __BOOST_CS_DEMO_SERVER_H__

#include "boost_cs_demo/cs_helper.h"

class Server
{
public:
    Server();
    void run();

private:
    void accept();
    void accept_handler(const boost::system::error_code& ec, socket_ptr sock);
    void write_handler(const boost::system::error_code& ec, socket_ptr sock);
    void read_handler(const boost::system::error_code& ec, socket_ptr sock);
    io_service m_io;
    acceptor m_acceptor;
    unsigned int count;
    char m_buffer[100];
};

#endif
