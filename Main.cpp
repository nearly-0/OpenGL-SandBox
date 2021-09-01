#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

int main()
{
    cout<<"A nondescript C++ program using the GLFW library, coded and built using VSCode"<<endl;
    cout<<"Initializing Graphics Library FramWork (GLFW)"<<endl;
    
    if(!glfwInit())
    {
        return -1;
    }

    GLFWwindow* pGameWindow = glfwCreateWindow(640, 480, "Personl OpenGL Sandbox", nullptr, nullptr);
    if(!pGameWindow)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(pGameWindow);

    float veticies[] = 
    {
        -0.5f, -0.5f, 0.f,
        0.5f, -0.5f, 0.f,
        0.f, 0.5f, 0.f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffers(GL_ARRAY_BUFFER, VBO);

    // glBufferData : A function specifically targeted to copy user_defined data into the currently bound buffer.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Application (Game) loop
    while(!glfwWindowShouldClose(pGameWindow))
    {
        //glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(pGameWindow);
        glfwPollEvents();
    }

    glfwTerminate();    

    pGameWindow = nullptr;

    return 0;
}