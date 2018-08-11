cmake_minimum_required (VERSION 3.3)
project (Test)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-g -std=c++11 -pthread")
find_package (Threads)
add_executable (elog
                main.cpp
                ../src/elog/record.cpp
                ../src/elog/logger.cpp
                ../src/elog/formatters/formatter.cpp
                ../src/elog/formatters/pattern_formatter.cpp
                ../src/elog/appenders/appender.cpp
                ../src/elog/appenders/console_appender.cpp)
target_link_libraries (elog  ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(elog PUBLIC ../src)
