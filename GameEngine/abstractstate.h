#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <camera.h>
#include <event.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class AbstractState
{
public:
    AbstractState();
    virtual ~AbstractState();
    virtual AbstractState* handle(Camera *camera, Event * event) = 0;
    virtual void update() = 0;
};

#endif // ABSTRACTSTATE_H
