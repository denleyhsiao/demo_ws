#ifndef __BOOST_CS_DEMO_CS_HELPER_H__
#define __BOOST_CS_DEMO_CS_HELPER_H__

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <boost/bind.hpp>
#include <boost/cstdint.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/asio/ip/tcp.hpp>

using namespace boost;
using namespace boost::asio;
using namespace std;

typedef ip::tcp::acceptor acceptor;
typedef ip::tcp::endpoint endpoint;
typedef std::shared_ptr<ip::tcp::socket> socket_ptr;

#endif
