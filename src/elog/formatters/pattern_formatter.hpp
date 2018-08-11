#pragma once

#include "formatter.hpp"
namespace elog
{
  class PatternFormatter: public Formatter
  {
  public:
    PatternFormatter(const char* pattern = "%+", bool colored = false);
    virtual ~PatternFormatter();
    std::string format(const Record& record) override;
  private:
    std::string percentString(char c, const Record& record);
    std::string pattern_;
    bool color_;
    bool colored_;
  };
}
