#pragma once

#include "elog/record.hpp"
#include "elog/formatters/formatter.hpp"
#include <string>

namespace elog
{
  class Appender
  {
  public:
    Appender(Formatter& formatter);
    virtual ~Appender();
    virtual void append(const Record& record) = 0;
  protected:
    Formatter* formatter_;
  };

  class RawAppender: public Appender
  {
  public:
    RawAppender(Formatter& formatter);
    ~RawAppender();
    void append(const Record& record) override;
  protected:
    virtual void write(const std::string&) = 0;
  };
}
