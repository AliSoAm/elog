namespace elog
{
  template<typename T>
  Record& Record::operator<<(const T& data)
  {
    message_ << data;
    return *this;
  }
}
