#pragma once

#include "formatter.hpp"
namespace elog
{
  class SimpleFormatter: public Formatter
  {
  public:
    SimpleFormatter();
    virtual ~SimpleFormatter();
    std::string format(const Record& record) override;
  private:
  };
}
