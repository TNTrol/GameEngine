#ifndef KEYBOARDEVENT_H
#define KEYBOARDEVENT_H

#include <event.h>



class KeyboardEvent: public Event
{
public:
    KeyboardEvent(const int &key, const int &scancode, const int &action, const int &mods);
    ~KeyboardEvent() override;
    Type type() override;
    int key();
    int scancode();
    int action();
    int mods();
private:
    int m_key, m_scancode, m_action, m_mods;

};

#endif // KEYBOARDEVENT_H
