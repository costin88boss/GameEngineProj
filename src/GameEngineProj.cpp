#include <GL/glew.h>
#include <glfw3.h>
#include <stdexcept>

int main()
{
    if (!glfwInit())
        throw std::runtime_error("FATAL: Failed to initialize GLFW3");

    GLFWwindow *window = glfwCreateWindow(720, 480, "Hello World", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        throw std::runtime_error("FATAL: Failed to create GLFW3 window");
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
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
    }

    glfwTerminate();
}
