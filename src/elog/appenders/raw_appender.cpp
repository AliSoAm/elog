#include "elog/appenders/raw_appender.hpp"

namespace elog
{
  RawAppender::RawAppender(Formatter& formatter): BaseAppender(formatter)
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
