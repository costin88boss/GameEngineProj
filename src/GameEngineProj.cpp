#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Debug.hpp"
#include "Time.hpp"

int main() {
  Time time{};
  time.startTimer("Lifetime");
  Debug::logLevel = ALL;

  if (!glfwInit()) {
    Debug::log(FATAL, "Failed to initialize GLFW");
    return 1;
  }

  GLFWwindow* window =
      glfwCreateWindow(720, 480, "Hello World", nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    Debug::log(FATAL, "Failed to create GLFW window");
    return 1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    time.startFrameTimer();

    glClear(GL_COLOR_BUFFER_BIT);

    // Yes, I know this is legacy OpenGL, it's just for testing.
    glBegin(GL_TRIANGLES);
    glColor3f(0.3f, 0.6f, 0.6f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();

    std::string title =
        "FPS: " + std::to_string(static_cast<int>(time.getFramesPerSecond()));
    glfwSetWindowTitle(window, title.c_str());
  }

  glfwTerminate();

  Debug::log(INFO, "Program lasted ", time.getTimerDuration("Lifetime"), 's');
  time.stopTimer("Lifetime");

  return 0;
}