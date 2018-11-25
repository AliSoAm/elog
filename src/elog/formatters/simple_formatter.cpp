#include "elog/formatters/simple_formatter.hpp"
#include "elog/severity.hpp"
#include <iomanip>

namespace elog
{
  SimpleFormatter::SimpleFormatter()
  {
  }

  SimpleFormatter::~SimpleFormatter()
  {
  }

  std::string SimpleFormatter::format(const Record& record)
  {
    std::stringstream line;
    line << '[' << std::put_time(&record.time(), "%F %T") << "] " << severityToStringA(record.severity()) << ' ' << record.message();
    return line.str();
  }
}
