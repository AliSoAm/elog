namespace elog
{
  template<typename T>
  Record& Record::operator<<(const T& data)
  {
    messageStream << data;
    return *this;
  }
}
