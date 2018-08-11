#pragma once

#ifndef ELOG_DEFAULT_INSTANCE
#define ELOG_DEFAULT_INSTANCE           0
#endif

#include "elog/severity.hpp"
#include "elog/appenders/appender.hpp"
#include <map>
#include <vector>
#include <initializer_list>

namespace elog
{
  class Logger
  {
  public:
    template <unsigned int instance>
    static void init(Severity maxSeverity = NONE, std::initializer_list<Appender*> appenders = {});
    template <unsigned int  instance>
    static Logger& get();

    Severity maxSeverity() const;
    void maxSeverity(Severity severity);
    Logger& addAppender(Appender* appender);
    virtual void write(const Record& record);
    Logger& operator+=(const Record& record);
    bool checkSeverity(Severity severity) const;

  private:
    static std::map<unsigned int, Logger*> instances;

    Severity maxSeverity_;
    std::vector<Appender*> appenders_;

    Logger(Severity maxSeverity = NONE, std::initializer_list<Appender*> = {});
    Logger& operator=(const Logger&) = delete;
  };

  template <unsigned int instance = ELOG_DEFAULT_INSTANCE>
  void init(Severity maxSeverity = NONE, std::initializer_list<Appender*> appenders = {});
  template <unsigned int instance = ELOG_DEFAULT_INSTANCE>
  Logger& get();
}
#include "logger.tpp"
