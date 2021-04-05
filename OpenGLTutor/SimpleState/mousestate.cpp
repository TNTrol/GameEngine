#include "mousestate.h"

#include <mouseevent.h>

MouseState::MouseState(AbstractState *state)
{
    m_state = state;
}

MouseState::~MouseState()
{}

AbstractState * MouseState::handle(Camera *camera, Event *event)
{
    if(event->type() != Event::GEMouseMove)
        return m_state;
    MouseEvent * eventm = (MouseEvent *) event;
    const float mouseSpeed = 0.005f;
    float horizontalAngle, verticalAngle;
    vec2 angle = camera->getAngle();
    horizontalAngle = angle[1] + mouseSpeed * float(eventm->x() );
    verticalAngle   = angle[0] + mouseSpeed * float( eventm->y());
    camera->setAngle(vec2(verticalAngle, horizontalAngle));
    return m_state;
}

void MouseState::update()
{}
