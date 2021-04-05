#include "maingamewindow.h"
#include <iostream>


MainGameWindow::MainGameWindow(int w, int h)
{
    if(!glfwInit()) {
      std::cerr << "Failed to initialize GLFW" << std::endl;
      assert(-1);
    }

    glfwDefaultWindowHints();

    GLFWwindow* window = glfwCreateWindow(w, h, "Red Triangle",nullptr, nullptr);
    glfwMakeContextCurrent(window);

    if (!window) {
        std::cout << "Window creation failed" << std::endl;
        assert(!window);
    }
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Couldn't initalize OpenGL" << std::endl;
        assert(glewInit() != GLEW_OK);
    }
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glEnable(GL_CULL_FACE);
    glfwSetCursorPos(window, w/2, h/2);
    m_window = window;
}

void MainGameWindow::setEvent(MainGameWindow::Callback callback)
{
    m_callback = callback;
}

void MainGameWindow::show(const std::vector<AbstractModel *> models)
{
    glm::mat4 view, project;
    do
    {
        #ifdef OTHER_GUI
        #else
            glfwPollEvents();
        #endif
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        view = m_camera->getViewMatrix();
        project = m_camera->getPprojectionMatrix(4.0f/3.0f);
        for(AbstractModel *model : models)
            model->draw(view, project);
        glfwSwapBuffers(m_window);
    }
    while(glfwGetKey(m_window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0 );
    glfwDestroyWindow(m_window);
    glfwTerminate();
}
