#include "elog/appenders/appender.hpp"
#include "elog/severity.hpp"

namespace elog
{
  BaseAppender::BaseAppender(Formatter& formatter): formatter_(&formatter)
  {
  }

  BaseAppender::~BaseAppender()
  {
  }
}
