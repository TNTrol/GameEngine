#include "mouseevent.h"

MouseEvent::MouseEvent(const double &x, const double &y)
{
    m_x = x;
    m_y = y;
}

MouseEvent::~MouseEvent()
{
}

Event::Type MouseEvent::type()
{
    return Type::GEMouseMove;
}

double MouseEvent::x()
{
    return m_x;
}

double MouseEvent::y()
{
    return m_y;
}
