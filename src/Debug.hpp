#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include "Time.hpp"

enum LogLevel {
  NONE    = 0,
  FATAL   = 1,
  ERROR   = 2,
  WARNING = 4,
  INFO    = 8,
  ALL     = 15
};

namespace Debug {

inline unsigned char logLevel;

template <typename... Args>
void log(const LogLevel level, const Args... args) {
  // Compare with logLevel Bitmask to see if level is included, return if not
  if (~logLevel & level)
    return;

  std::ostringstream stream;
  stream << '[' << Time::getDateAndTime() << "] ";

  std::string logLevelString;

  switch (level) {
    case FATAL:
      logLevelString = "FATAL";
      break;
    case ERROR:
      logLevelString = "ERROR";
      break;
    case WARNING:
      logLevelString = "WARN";
      break;
    case INFO:
      logLevelString = "INFO";
      break;
    default:
      Debug::log(ERROR, "Invalid log level specified");
      return;
  }

  stream << '[' << logLevelString << "] ";
  (stream << ... << args);

  std::cout << stream.str() << '\n';
}
}  // namespace Debug