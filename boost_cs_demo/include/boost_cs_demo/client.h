#ifndef __BOOST_CS_DEMO_CLIENT_H__
#define __BOOST_CS_DEMO_CLIENT_H__

#include "boost_cs_demo/cs_helper.h"

class Client
{
public:
  Client();
  void run();
  
private:
  void start();
  void conn_handler(const boost::system::error_code& ec, socket_ptr sock);
  void read_handler(const boost::system::error_code& ec, socket_ptr sock);
  io_service m_io;
  char m_buffer[100];
  endpoint m_ep;
};

#endif
