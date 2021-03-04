#include "Window.h"

Window::Window(const int width, const int height, GLFWcursorposfun fncPtr){
    glfwInit();
    window = glfwCreateWindow(width, height, "Star Viewer", NULL,NULL);
    ptr = window;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewInit();
    //glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, fncPtr);
}

bool Window::shouldClose(){
    if(glfwWindowShouldClose(window)){
        return true;
    }else{
        return false;
    }
}

void Window::Update(){
   glfwSwapBuffers(window);
   glfwPollEvents();
}
