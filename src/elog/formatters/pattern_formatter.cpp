#include "elog/formatters/pattern_formatter.hpp"
#include "elog/severity.hpp"

namespace elog
{
  const char* PatternFormatter::abbreviatedWeekdayName(const struct tm& t)
  {
    switch (t.tm_wday)
    {
    case 0: return "Sun";
    case 1: return "Mon";
    case 2: return "Tue";
    case 3: return "Wed";
    case 4: return "Thu";
    case 5: return "Fri";
    case 6: return "Sat";
    }
    return "";
  }

  const char* PatternFormatter::fullWeekdayName(const struct tm& t)
  {
    switch (t.tm_wday)
    {
    case 0: return "Sunday";
    case 1: return "Monday";
    case 2: return "Tuesday";
    case 3: return "Wednesday";
    case 4: return "Thursday";
    case 5: return "Friday";
    case 6: return "Satarday";
    }
    return "";
  }
  const char* PatternFormatter::abbreviatedMounthName(const struct tm& t)
  {
    switch (t.tm_wday)
    {
    case 0: return "Jan";
    case 1: return "Feb";
    case 2: return "Mar";
    case 3: return "Apr";
    case 4: return "May";
    case 5: return "Jun";
    case 6: return "Jul";
    case 7: return "Aug";
    case 8: return "Sep";
    case 9: return "Oct";
    case 10: return "Nov";
    case 11: return "Dec";
    }
    return "";
  }

  const char* PatternFormatter::fullMonthName(const struct tm& t)
  {
    switch (t.tm_wday)
    {
    case 0: return "January";
    case 1: return "February";
    case 2: return "March";
    case 3: return "April";
    case 4: return "May";
    case 5: return "June";
    case 6: return "July";
    case 7: return "August";
    case 8: return "September";
    case 9: return "October";
    case 10: return "November";
    case 11: return "December";
    }
    return "";
  }

  std::string PatternFormatter::percentString(char c, const Record& record)
  {
    switch (c)
    {
    case 'v': return record.message(); break;
    case 'n': break;
    case 'l':
      return std::string((colored_ ? severityColor(record.severity()) : "")) +
             severityToString(record.severity()) +
             std::string((colored_ ? "\033[0m" : ""));
    case 'L':
      return std::string((colored_ ? severityColor(record.severity()) : " ")) +
             severityToStringA(record.severity()) +
             std::string((colored_ ? "\033[0m" : ""));
    case 'a': return abbreviatedWeekdayName(record.time());
    case 'A': return fullWeekdayName(record.time());
    case 'b': return abbreviatedMounthName(record.time());
    case 'B': return fullMonthName(record.time());
    case 'c': return percentString('a', record) + " " + percentString('b', record) + " " + percentString('d', record) + " " + " " + percentString('Y', record);
    case 'C': return std::to_string(record.time().tm_year % 100);
    case 'Y': return std::to_string(record.time().tm_year + 1900);
    case 'D': case 'x': return percentString('m', record) + "/" + percentString('d', record) + "/" + percentString('C', record);
    case 'd': return std::to_string(record.time().tm_mon + 1);
    case 'm': return std::to_string(record.time().tm_mday);
    case 'H': return std::to_string(record.time().tm_hour);
    case 'I': return std::to_string(record.time().tm_hour % 12);
    case 'M': return std::to_string(record.time().tm_min);
    case 'S': return std::to_string(record.time().tm_sec);
    case 'e': return "000";
    case 'f': return "000000";
    case 'F': return "000000000";
    case 'p': return (record.time().tm_hour < 12? "AM": "PM");
    case 'r': return percentString('I', record) + ":" + percentString('M', record) + ":" + percentString('S', record) + " " + percentString('p', record);
    case 'R': return percentString('H', record) + ":" + percentString('M', record);
    case 'T': case 'X': return percentString('H', record) + ":" + percentString('M', record) + ":" + percentString('S', record);
    case 'z': break;
    case 'E': {struct tm tm_ = record.time(); time_t t = std::mktime(&tm_); return std::to_string(t);}
    case 'i': break;
    case '%': return "%";
    case '+':
      return (colored_ ? "[\033[37m" : "[") +
             percentString('Y', record) + "-" +
             percentString('d', record) + "-" +
             percentString('m', record) + " " +
             percentString('T', record) +
             (colored_ ? "\033[0m]" : "]") +
             percentString('l', record) + " " +
             percentString('v', record);
    case '^': color_ = true; break ;
    case '$': color_ = false; break;
    }
    return "";
  }

  PatternFormatter::PatternFormatter(const char* pattern, bool colored): pattern_(pattern), colored_(colored)
  {
  }

  PatternFormatter::~PatternFormatter()
  {
  }

  std::string PatternFormatter::format(const Record& record)
  {
    std::string line;
    bool percent = false;
    for (char c: pattern_)
    {
      if (c == '%')
        percent = true;
      else if (percent)
      {
        percent = false;
        line += percentString(c, record);
      }
      else
        line += c;
    }
    return line;
  }
}
