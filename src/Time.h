#pragma once

#include <chrono>
#include <string>
#include <unordered_map>

class Time {
 public:
  Time();
  ~Time();

  void StartFrameTimer();
  void EndFrameTimer();
  [[nodiscard]] float GetDeltaTime() const;

  void StartTimer(const std::string& name);
  void StopTimer(const std::string& name);
  [[nodiscard]] float GetTimerDuration(const std::string& name) const;

 private:
  std::chrono::time_point<std::chrono::steady_clock> m_FrameStartTime,
      m_FrameEndTime;
  std::unordered_map<std::string,
                     std::chrono::time_point<std::chrono::steady_clock> >
      m_Timers;
};