#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <abstractmodel.h>
#include <abstractstate.h>
#include <camera.h>
#include <event.h>
#include <iostream>
#include <vector>
#include <maingamewindow.h>

class Controller
{
public:
    Controller(Camera *camera, AbstractState *state, int w, int h);
    ~Controller();
    void run(const std::vector<AbstractModel *> model);
protected:
    void call_state(Event *event);
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void mouse_move_callback(GLFWwindow* window, double x, double y);
protected:
    Camera *m_camera;
    GLFWwindow *m_window;
    AbstractState *m_state;
};

#endif // CONTROLLER_H
