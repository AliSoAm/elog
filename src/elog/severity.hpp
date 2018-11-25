#pragma once

namespace elog
{
  enum Severity
  {
    NONE = 0,
    FATAL = 1,
    ERROR = 2,
    WARNING = 3,
    INFO = 4,
    DEBUG = 5,
    VERBOSE = 6
  };

  inline const char* severityToString(Severity severity)
  {
    switch (severity)
    {
    case FATAL:
      return "Fatal";
    case ERROR:
      return "Error";
    case WARNING:
      return "Warn ";
    case INFO:
      return "Info ";
    case DEBUG:
      return "Debug";
    case VERBOSE:
      return "Verb ";
    default:
      return "None ";
    }
  }

  inline const char* severityToStringA(Severity severity)
  {
    switch (severity)
    {
    case FATAL:
      return "F";
    case ERROR:
      return "E";
    case WARNING:
      return "W";
    case INFO:
      return "I";
    case DEBUG:
      return "D";
    case VERBOSE:
      return "V";
    default:
      return "N";
    }
  }

  inline Severity severityFromString(const char* str)
  {
    for (Severity severity = FATAL; severity <= VERBOSE; severity = static_cast<Severity>(severity + 1))
    {
      if (severityToString(severity)[0] == str[0])
      {
        return severity;
      }
    }
    return NONE;
  }

  inline const char* severityColor(Severity s)
  {
    switch (s)
    {
      case FATAL:
      case ERROR:
        return " \033[31m";
      case WARNING:
        return " \033[33m";
      case INFO:
        return " \033[34m";
      case DEBUG:
        return " \033[32m";
      case VERBOSE:
        return " \033[35m";
    }
    return " \033[0m";
  }
}
