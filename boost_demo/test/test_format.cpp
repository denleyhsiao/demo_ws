#include <gtest/gtest.h>
#include <boost/format.hpp>

TEST(String, format)
{
  boost::format actualValue = boost::format("My name is %s, and age is %d") % "Denley Hsiao" % 28;
  ASSERT_EQ("My name is Denley Hsiao, and age is 28", actualValue.str());
}
