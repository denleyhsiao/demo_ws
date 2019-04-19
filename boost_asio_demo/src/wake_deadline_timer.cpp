#include "boost_asio_demo/wake_deadline_timer.h"
#include "boost/format.hpp"

WakeDeadlineTimer::WakeDeadlineTimer(boost::asio::io_service& io, float sleepSeconds, unsigned int maxOffsetSeconds, DeadlineTimer* otherTimer, finish_func_type callbackFinish) 
  : DeadlineTimer(io, sleepSeconds, callbackFinish), offsetSeconds(0), maxOffsetSeconds(maxOffsetSeconds), otherTimer(otherTimer)
{
  
}

bool WakeDeadlineTimer::isPaused(const boost::system::error_code &err) const
{
  return (offsetSeconds < maxOffsetSeconds);
}

void WakeDeadlineTimer::pause()  
{  
  print("start wakeUp");
  otherTimer->wakeUp();
  timer->expires_from_now(sleepDuration + boost::posix_time::seconds(++offsetSeconds));  
}  

void WakeDeadlineTimer::print(const char* prefix)
{
  doPrint((boost::format("Wake %s at ") % prefix).str().c_str());
}