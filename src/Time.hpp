#pragma once

#include <chrono>
#include <string>
#include <unordered_map>

class Time {
 public:
  [[nodiscard]] static std::string getDateAndTime() ;

 public:
  void startFrameTimer();
  [[nodiscard]] float getDeltaTime() const;
  [[nodiscard]] float getFramesPerSecond() const;

  void startTimer(const std::string& name);
  void restartTimer(const std::string& name);
  void stopTimer(const std::string& name);
  [[nodiscard]] float getTimerDuration(const std::string& name) const;

 private:
  std::chrono::time_point<std::chrono::steady_clock> m_frameTime;
  std::unordered_map<std::string,
                     std::chrono::time_point<std::chrono::steady_clock> >
      m_timers;
};