#include "elog/formatters/colored_formatter.hpp"
#include "elog/severity.hpp"
#include <iomanip>
#include <sstream>

namespace elog
{
   ColoredFormatter::ColoredFormatter()
  {
  }

  ColoredFormatter::~ColoredFormatter()
  {
  }

  std::string ColoredFormatter::format(const Record& record)
  {
    std::stringstream line;
    line << "[\033[37m" << std::put_time(&record.time(), "%F %T") << "\033[0m]" << severityColor(record.severity()) << severityToString(record.severity()) << "\033[0m " << record.message();
    return line.str();
  }
}
