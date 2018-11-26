#pragma once

#include "elog/record.hpp"
#include "elog/formatters/formatter.hpp"

namespace elog
{
  class BaseAppender
  {
  public:
    BaseAppender(Formatter& formatter);
    virtual ~BaseAppender();
    virtual void append(const Record& record) = 0;
  protected:
    Formatter* formatter_;
  };
}
