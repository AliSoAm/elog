#pragma once

#include "formatter.hpp"
namespace elog
{
  class ColoredFormatter: public Formatter
  {
  public:
    ColoredFormatter();
    virtual ~ColoredFormatter();
    std::string format(const Record& record) override;
  private:
  };
}
