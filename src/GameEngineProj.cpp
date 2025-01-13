#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Time.hpp"

int main() {
  Time time{};
  time.StartTimer("Lifetime");

  if (!glfwInit())
    throw std::runtime_error("FATAL: Failed to initialize GLFW3");

  GLFWwindow* window =
      glfwCreateWindow(720, 480, "Hello World", nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    throw std::runtime_error("FATAL: Failed to create GLFW3 window");
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    time.StartFrameTimer();

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

    time.EndFrameTimer();
    std::cout << "Frame Time:" << time.GetDeltaTime()
              << "s, FPS: " << 1 / time.GetDeltaTime() << '\n';
  }

  glfwTerminate();

  std::cout << "Program lasted " << time.GetTimerDuration("Lifetime") << "s\n";
  time.StopTimer("Lifetime");
}