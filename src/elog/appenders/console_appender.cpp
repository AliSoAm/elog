#include "elog/appenders/console_appender.hpp"
#include <iostream>

namespace elog
{
  ConsoleAppender::ConsoleAppender(Formatter& formatter): RawAppender(formatter)
  {
  }

  void ConsoleAppender::write(const std::string& line)
  {
    std::cout << line << std::endl;
    std::cout.flush();
  }
}
