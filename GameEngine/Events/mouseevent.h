#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <event.h>



class MouseEvent: public Event
{
public:
    MouseEvent(const double &x, const double &y);
    ~MouseEvent() override;
    Event::Type type() override;
    double x();
    double y();
private:
    int m_x, m_y;
};

#endif // MOUSEEVENT_H
