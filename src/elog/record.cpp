#include "record.hpp"
#include <cstring>

namespace elog
{
# ifdef ELOG_STATIC_RECORD
    RecordBuf::RecordBuf()
    {
      std::memset(buffer_, 0, ELOG_RECORD_LEN);
      if (ELOG_RECORD_LEN <= 0)
      {
        buffer_[0] = 0;
        return;
      }
      buffer_[ELOG_RECORD_LEN - 1] = 0;
      setp(buffer_, buffer_ + ELOG_RECORD_LEN - 1);
    }
    const char* RecordBuf::buffer() const
    {
      return buffer_;
    }
# endif
  Record::Record(Severity severity, const char* func, size_t line, const char* file): severity_(severity), func_(func), line_(line), file_(file)
# ifdef ELOG_STATIC_RECORD
    , messageStream(&recordBuffer)
# endif
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
#ifdef ELOG_STATIC_RECORD
  const char* Record::message() const
  {
    return recordBuffer.buffer();
  }
#else
  std::string Record::message() const
  {
    return messageStream.str();
  }
#endif

  const char* Record::functionName() const
  {
    return func_;
  }

  const char* Record::fileName() const
  {
    return file_;
  }
}
