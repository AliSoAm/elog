#include "elog/appenders/appender.hpp"
#include "elog/severity.hpp"

namespace elog
{

  Appender::Appender(Formatter& formatter): formatter_(&formatter)
  {
  }

  Appender::~Appender()
  {
  }

  RawAppender::RawAppender(Formatter& formatter): Appender(formatter)
  {
  }

  RawAppender::~RawAppender()
  {
  }

  void RawAppender::append(const Record& record)
  {
    std::string line = (*formatter_)(record);
    write(line);
  }

}
