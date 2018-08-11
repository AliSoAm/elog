#include "record.hpp"

namespace elog
{
  Record::Record(Severity severity, const char* func, size_t line, const char* file): severity_(severity), func_(func), line_(line), file_(file)
  {
    time_t t;
    t = std::time(nullptr);
    localtime_r(&t, &time_);
  }

  Record::~Record()
  {
  }

  const struct tm& Record::time() const
  {
    return time_;
  }

  Severity Record::severity() const
  {
    return severity_;
  }

  size_t Record::line() const
  {
    return line_;
  }

  std::string Record::message() const
  {
    return message_.str();
  }

  const char* Record::functionName() const
  {
    return func_;
  }

  const char* Record::fileName() const
  {
    return file_;
  }
}
