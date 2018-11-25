#include "elog/log.hpp"
#include "elog/appenders/console_appender.hpp"
#include "elog/formatters/pattern_formatter.hpp"
#include "elog/formatters/colored_formatter.hpp"
#include "elog/formatters/simple_formatter.hpp"

using namespace std;

int main(int argc, char** argv)
{
  elog::PatternFormatter formatter0("%+", true);
  elog::ColoredFormatter formatter1;
  elog::SimpleFormatter formatter2;
  elog::ConsoleAppender appender0(formatter0);
  elog::ConsoleAppender appender1(formatter1);
  elog::ConsoleAppender appender2(formatter2);

  elog::init(elog::VERBOSE, {&appender0, &appender1, &appender2});
  try
  {
  }
  catch (std::exception& e)
  {
    return EXIT_FAILURE;
  }
  auto i = elog::get<0>();
  elog::Record j(elog::FATAL, __func__, __LINE__, __FILE__);
  j << "TEST";
  i+= j;
  i += elog::Record(elog::FATAL, __func__, __LINE__, __FILE__) << "TEST";
  if (true)
    LOGF << "TEST true";
  if (false)
    LOGE << "TEST2 false";
  LOGF << "TEST";
  LOGE << "TEST";
  LOGI << "TEST";
  LOGD << "TEST";
  LOGV << "TEST";
  LOGW << "TEST";
  LOGN << "TEST";
  return EXIT_SUCCESS;
}
