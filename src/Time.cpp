#include "Time.hpp"

#include <chrono>
#include <string>
#include <unordered_map>

Time::Time() = default;
Time::~Time() = default;

void Time::StartFrameTimer() {
  m_FrameStartTime = std::chrono::steady_clock::now();
}

void Time::EndFrameTimer() {
  m_FrameEndTime = std::chrono::steady_clock::now();
}

void Time::StartTimer(const std::string& name) {
  m_Timers[name] = std::chrono::steady_clock::now();
}

float Time::GetTimerDuration(const std::string& name) const {
  if (!m_Timers.contains(name))
    throw std::invalid_argument("ERR: Timer '" + name + "' not found");

  const auto duration = std::chrono::steady_clock::now() - m_Timers.at(name);
  return std::chrono::duration<float>(duration).count();
}

void Time::StopTimer(const std::string& name) {
  if (!m_Timers.contains(name))
    throw std::invalid_argument("ERR: Timer '" + name + "' not found");

  m_Timers.erase(name);
}

float Time::GetDeltaTime() const {
  return std::chrono::duration<float>(m_FrameEndTime - m_FrameStartTime)
      .count();
}