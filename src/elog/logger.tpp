
namespace elog
{

  template <unsigned int instance>
  void Logger::init(Severity maxSeverity, std::initializer_list<BaseAppender*> appenders)
  {
    if (instances.count(instance) == 0)
      instances.emplace(instance, new Logger(maxSeverity, appenders));
  }

  template <unsigned int instance>
  Logger& Logger::get()
  {
    return *(instances.at(instance));
  }

  template <unsigned int instance>
  void init(Severity maxSeverity, std::initializer_list<BaseAppender*> appenders)
  {
    Logger::init<instance>(maxSeverity, appenders);
  }

  template <unsigned int instance>
  Logger& get()
  {
    return Logger::get<instance>();
  }

}
