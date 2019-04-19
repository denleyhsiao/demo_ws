#ifndef __BOOST_ASIO_DEMO_DELAY_DEADLINE_TIMER_H__
#define __BOOST_ASIO_DEMO_DELAY_DEADLINE_TIMER_H__

#include "boost_asio_demo/deadline_timer.h"

class DelayDeadlineTimer : public DeadlineTimer
{
public:
  typedef DeadlineTimer::finish_func_type finish_func_type;
  DelayDeadlineTimer(boost::asio::io_service& io, float sleepSeconds, finish_func_type callbackFinish) : DeadlineTimer(io, sleepSeconds, callbackFinish) { }
  
private:
  virtual bool isPaused(const boost::system::error_code &err) const;
  virtual void pause(); 
  virtual void print(const char* prefix);
  bool isSameTime() const;
};

#endif
