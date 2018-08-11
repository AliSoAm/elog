#include "elog/log.hpp"
#include "elog/appenders/console_appender.hpp"
#include "elog/formatters/pattern_formatter.hpp"

using namespace std;

int main(int argc, char** argv)
{
  elog::PatternFormatter formatter("%+", true);
  elog::ConsoleAppender appender(formatter);
  elog::init(elog::VERBOSE, {&appender});
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
  LOGF << "TEST";
  LOGE << "TEST2";
  LOGI << "TEST";
  LOGD << "TEST";
  LOGV << "TEST";
  LOGW << "TEST";
  LOGN << "TEST";
  return EXIT_SUCCESS;
}
