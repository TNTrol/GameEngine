#include "keyboardevent.h"


KeyboardEvent::KeyboardEvent(const int &key, const int &scancode, const int &action, const int &mods)
{
   m_key = key;
   m_scancode = scancode;
   m_action = action;
   m_mods = mods;
}

KeyboardEvent::~KeyboardEvent()
{
}

Event::Type KeyboardEvent::type()
{
    return Type::GEKeyboard;
}

int KeyboardEvent::key()
{
    return m_key;
}

int KeyboardEvent::scancode()
{
    return m_scancode;
}

int KeyboardEvent::action()
{
    return m_action;
}

int KeyboardEvent::mods()
{
    return m_mods;
}
