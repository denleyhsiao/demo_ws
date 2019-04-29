#include "boost_asio_demo/delay_deadline_timer.h"
#include "boost_asio_demo/wake_deadline_timer.h"
#include <iostream>

void masterCallback()
{
  std::cout<<"Master is power off"<<std::endl;
}

void wakeCallback()
{
  std::cout<<"Wake is finished"<<std::endl;
}

int main()
{
  boost::asio::io_service io;
  DelayDeadlineTimer master(io, 5.0, masterCallback);
  WakeDeadlineTimer wake(io, 2.0, 5, &master, wakeCallback);
  master.init();
  wake.init();
  io.run();
  return 0;
}
