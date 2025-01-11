#include "GameEngineProj.h"
#include "glfw3.h"
#include <iostream>

int main() {
  glfwInit();

  auto a = glfwCreateWindow(500, 500, "Cancer", 0, 0);
  while (!glfwWindowShouldClose(a)) {
    glfwPollEvents();
  }
  std::cout << "It fucking works!?!?!? \n";
  glfwTerminate();
}