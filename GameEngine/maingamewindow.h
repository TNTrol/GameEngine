#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <abstractmodel.h>
#include <camera.h>
#include <event.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

//#define OTHER_GUI

class MainGameWindow
{
public:
    typedef bool (*Callback)( Camera *, Event*);
    MainGameWindow(int w, int h);
    void setEvent(Callback callback);
    void show(const std::vector<AbstractModel *> models);
protected:
    GLFWwindow* m_window;
    Camera* m_camera;
    Callback m_callback;
};

#endif // MAINGAMEWINDOW_H
