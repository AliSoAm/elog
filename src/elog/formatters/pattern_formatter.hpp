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
    std::string pattern_;
    bool color_;
    bool colored_;
    const char* abbreviatedWeekdayName(const struct tm& t);
    const char* fullWeekdayName(const struct tm& t);
    const char* abbreviatedMounthName(const struct tm& t);
    const char* fullMonthName(const struct tm& t);
    std::string percentString(char c, const Record& record);
  };
}
