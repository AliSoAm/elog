#pragma once

#include "elog/record.hpp"

namespace elog
{
  class Formatter
  {
  public:
    virtual ~Formatter();
    virtual std::string format(const Record& record) = 0;
    virtual std::string operator()(const Record& record);
  };
}
