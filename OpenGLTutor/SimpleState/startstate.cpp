#include "startstate.h"

#include <keyboardevent.h>
#include <mousestate.h>

StartState::StartState()
{

}

StartState::~StartState()
{

}

AbstractState *StartState::handle(Camera *m_camera, Event * event)
{
    if(event->type() == Event::GEKeyboard){
        const float speed = 0.035f;
        const float speedr = speed * 0.5f;
        static double lastTime = glfwGetTime();
        double currentTime = glfwGetTime();
        float deltaTime = float(currentTime - lastTime);
        KeyboardEvent * eventk = (KeyboardEvent*) event;
        if (eventk->key() ==  GLFW_KEY_UP ){
            m_camera->setPosition(m_camera ->getPosition() + m_camera->getDirection() * deltaTime * speed);
            return this;
        }
        if (eventk->key() == GLFW_KEY_DOWN){
            m_camera->setPosition(m_camera ->getPosition() - m_camera->getDirection() * deltaTime * speed);
            return this;
        }
        if (eventk->key() == GLFW_KEY_RIGHT){
            m_camera->setPosition(m_camera ->getPosition() + m_camera->getRihtVec3() * deltaTime * speedr);
            return this;
        }
        if (eventk->key() == GLFW_KEY_LEFT ){
            m_camera->setPosition(m_camera ->getPosition() - m_camera->getRihtVec3() * deltaTime * speedr);
            return this;
        }
        return this;
    }
    else if(event->type() == Event::GEMouseMove)
    {
        MouseState *state = new MouseState(this);
        AbstractState *res_state = state->handle(m_camera, event);
        delete state;
        return res_state;
    }
    return nullptr;
}

void StartState::update()
{

}
