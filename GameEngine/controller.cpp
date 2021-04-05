#include "controller.h"
#include <iostream>
#include <keyboardevent.h>

#include <mouseevent.h>


Controller::~Controller()
{
    delete m_camera;
    delete m_state;
}

void Controller:: key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    call_state(new KeyboardEvent(key, scancode, action, mods));
}

void Controller::mouse_move_callback(GLFWwindow *window, double x, double y)
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    width /= 2;
    height /= 2;
    glfwSetCursorPos(m_window, width, height);
    call_state(new MouseEvent(width - x, height- y));

}

void Controller::run(const std::vector<AbstractModel *> models)
{
    do
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        for(AbstractModel *model : models)
            model->draw(m_camera->getViewMatrix(), m_camera->getPprojectionMatrix(4.0f/3.0f));
        glfwSwapBuffers(m_window);
    }
    while(glfwGetKey(m_window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0 );
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Controller::call_state(Event *event)
{
    AbstractState *state = m_state->handle(m_camera, event );
    delete event;
    if(state == m_state || !state)
        return;
    delete m_state;
    m_state = state;
}

Controller::Controller( Camera *camera, AbstractState *state, int w, int h)
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
    m_window = window;
    m_camera = camera;
    m_state = state;

    if(m_state)
    {
        #ifdef OTHER_GUI

        #else
            auto keyCallback = []( GLFWwindow* window, int key, int scancode, int action, int mods ) {
                    auto me = (Controller*)glfwGetWindowUserPointer( window );
                    me->key_callback( window, key, scancode, action, mods );
                    };
            auto moveCallback = []( GLFWwindow* window, double x, double y ) {
                    auto me = (Controller*)glfwGetWindowUserPointer( window );
                    me->mouse_move_callback(window, x, y);
                    };
            glfwSetWindowUserPointer( window, this );
            glfwSetKeyCallback( window, keyCallback );
            glfwSetCursorPosCallback(window, moveCallback);
        #endif
    }



    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glEnable(GL_CULL_FACE);
    glfwSetCursorPos(window, w/2, h/2);

}
