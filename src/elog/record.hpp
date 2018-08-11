#pragma once
#include "severity.hpp"
#include <string>
#include <ctime>
#include <sstream>

namespace elog
{
  class Record
  {
  public:
    Record(Severity severity, const char* func, size_t line, const char* file);
    virtual ~Record();
    template<typename T>
    Record& operator<<(const T& data);

    virtual const struct tm& time() const;
    virtual Severity severity() const;
    virtual size_t line() const;
    virtual std::string message() const;
    virtual const char* functionName() const;
    virtual const char* fileName() const;
  private:
    Severity severity_;
    struct tm time_;
    const char* file_;
    size_t line_;
    const char* func_;
    std::stringstream message_;
  };
}
#include "elog/record.tpp"
