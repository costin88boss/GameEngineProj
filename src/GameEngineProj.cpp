#include "GameEngineProj.h"

int main()
{
    
    //a = 2;


    glfwInit();

    
    auto a = glfwCreateWindow(500, 500, "Cancer", 0, 0);
    while (!glfwWindowShouldClose(a)) {
        glfwPollEvents();
    }
    std::cout << "It fucking works!?!?!? \n";
    glfwTerminate();
}