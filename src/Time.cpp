#include "Time.hpp"

#include <chrono>
#include <string>
#include <unordered_map>
#include "Debug.hpp"

void Time::startFrameTimer() {
  m_frameTime = std::chrono::steady_clock::now();
}

void Time::startTimer(const std::string& name) {
  m_timers[name] = std::chrono::steady_clock::now();
}

void Time::restartTimer(const std::string& name) {
  if (!m_timers.contains(name)) {
    Debug::log(ERROR, "Timer '" + name + "' not found");
    return;
  }

  m_timers[name] = std::chrono::steady_clock::now();
}

float Time::getTimerDuration(const std::string& name) const {
  if (!m_timers.contains(name)) {
    Debug::log(ERROR, "Timer '" + name + "' not found");
    return -1;
  }

  const auto duration = std::chrono::steady_clock::now() - m_timers.at(name);
  return std::chrono::duration<float>(duration).count();
}

std::string Time::getDateAndTime() {
  const auto now = std::chrono::system_clock::now();
  const auto currentTime = std::chrono::system_clock::to_time_t(now);

  std::string currentTimeString = ctime(&currentTime);
  currentTimeString.pop_back();

  return currentTimeString;
}

void Time::stopTimer(const std::string& name) {
  if (!m_timers.contains(name)) {
    Debug::log(ERROR, "Timer '" + name + "' not found");
    return;
  }

  m_timers.erase(name);
}

float Time::getDeltaTime() const {
  const auto deltaTime = std::chrono::steady_clock::now() - m_frameTime;
  return std::chrono::duration<float>(deltaTime).count();
}

float Time::getFramesPerSecond() const {
  return 1.0f / getDeltaTime();
}