#include "dev_lib/dev_helper.h"
#include "dev_lib/boost_helper.h"
#include "dev_lib/os_helper.h"
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

void print(const DevHelper::floats_type& values, bool showValues = false)
{
  std::cout<<values.size()<<std::endl;
  if (!showValues)
    return ;

  for (float value : values)
    std::cout<<value<<std::endl;
}

int main(int argc, const char* argv[])
{
  std::string moduleFileName = OSHelper::getModuleFileName();
  std::string fileName = (boost::filesystem::path(moduleFileName.c_str()).parent_path()/"../../dev_lib_demo/data/mock_laser_data.txt").string();
  boost::iostreams::stream<boost::iostreams::file_source> file(fileName.c_str());
  while(true)
  {
    std::string line = DevHelper::getLine(file);
    if (line.empty())
      break;
    print(BoostHelper::split(line.c_str()));
  }

  return 0;
}
