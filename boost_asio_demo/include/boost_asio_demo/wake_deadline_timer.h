#ifndef __BOOST_ASIO_DEMO_WAKE_DEADLINE_TIMER_H__
#define __BOOST_ASIO_DEMO_WAKE_DEADLINE_TIMER_H__

#include "boost_asio_demo/deadline_timer.h"

class WakeDeadlineTimer : public DeadlineTimer
{
public:
  typedef DeadlineTimer::finish_func_type finish_func_type;
  WakeDeadlineTimer(boost::asio::io_service& io, float sleepSeconds, unsigned int maxOffsetSeconds, DeadlineTimer* otherTimer, finish_func_type callbackFinish);
  
private:
  virtual bool isPaused(const boost::system::error_code &err) const;
  virtual void pause(); 
  virtual void print(const char* prefix);
  unsigned int offsetSeconds;
  unsigned int maxOffsetSeconds;
  DeadlineTimer* otherTimer;
};

#endif
