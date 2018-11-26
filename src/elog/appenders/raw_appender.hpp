#pragma once

#include "elog/appenders/appender.hpp"
#include <string>

namespace elog
{
  class RawAppender: public BaseAppender
  {
  public:
    RawAppender(Formatter& formatter);
    ~RawAppender();
    void append(const Record& record) override;
  protected:
    virtual void write(const std::string&) = 0;
  };
}
