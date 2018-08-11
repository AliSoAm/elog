#pragma once

#include "elog/appenders/appender.hpp"
#include "elog/formatters/formatter.hpp"

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
