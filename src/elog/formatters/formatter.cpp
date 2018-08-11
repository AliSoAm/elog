#include "formatter.hpp"

namespace elog
{
  Formatter::~Formatter()
  {
  }

  std::string Formatter::operator()(const Record& record)
  {
    return format(record);
  }
}
