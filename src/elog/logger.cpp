#include "elog/logger.hpp"
namespace elog
{
  std::map<unsigned int, Logger*> Logger::instances;

  Logger::Logger(Severity maxSeverity, std::initializer_list<BaseAppender*> appenders): maxSeverity_(maxSeverity), appenders_(appenders)
  {
  }

  Logger& Logger::addAppender(BaseAppender* appender)
  {
    appenders_.push_back(appender);
    return *this;
  }

  Severity Logger::maxSeverity() const
  {
    return maxSeverity_;
  }

  void Logger::maxSeverity(Severity severity)
  {
    maxSeverity_ = severity;
  }

  void Logger::write(const Record& record)
  {
    for (auto& appender: appenders_)
    {
      appender->append(record);
    }
  }

  Logger& Logger::operator+=(const Record& record)
  {
    write(record);
    return *this;
  }

  bool Logger::checkSeverity(Severity severity) const
  {
    return severity <= maxSeverity_;
  }
}
