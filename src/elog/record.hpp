#pragma once
#include "severity.hpp"
#include <ctime>

#ifdef ELOG_STATIC_RECORD
# ifndef ELOG_RECORD_LEN
#   define ELOG_RECORD_LEN 26
# endif
# include <ostream>
# include <streambuf>
#else
# include <sstream>
# include <string>
#endif

namespace elog
{
# ifdef ELOG_STATIC_RECORD
    class RecordBuf: public std::streambuf
    {
    public:
      RecordBuf();
      const char* buffer() const;
    private:
      char buffer_[ELOG_RECORD_LEN];
    };
# endif

  class Record
  {
  public:
    Record(Severity severity, const char* func, size_t line, const char* file);
    ~Record();
    template<typename T>
    Record& operator<<(const T& data);

    const struct tm& time() const;
    Severity severity() const;
    size_t line() const;
#   ifdef ELOG_STATIC_RECORD
      const char* message() const;
#   else
      std::string message() const;
#   endif
    const char* functionName() const;
    const char* fileName() const;
  private:
    struct tm time_;
    Severity severity_;
    size_t line_;
    const char* file_;
    const char* func_;
#   ifdef ELOG_STATIC_RECORD
      RecordBuf recordBuffer;
      std::ostream messageStream;
#   else
      std::ostringstream messageStream;
#   endif
  };
}
#include "elog/record.tpp"
