#pragma once

#include "elog/appenders/raw_appender.hpp"

namespace elog
{
  class ConsoleAppender: public RawAppender
  {
  public:
    ConsoleAppender(Formatter& formatter);
  private:
    void write(const std::string& line) override;
  };
}
