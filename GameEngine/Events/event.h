#ifndef EVENT_H
#define EVENT_H

class Event
{

public:
    enum Type{GEMouseMove,  GEMouseButton, GEWheel, GEKeyboard};
    Event();
    virtual ~Event();
    virtual Type type() = 0;


};

#endif // EVENT_H
