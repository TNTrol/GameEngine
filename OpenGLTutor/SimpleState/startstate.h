#ifndef STARTSTATE_H
#define STARTSTATE_H

#include <abstractstate.h>
#define SPEED_DIRECTION 0.035f
#define SPEED_RIGHT 0.0175f


class StartState: public AbstractState
{
public:
    StartState();
    ~StartState() override;
    AbstractState* handle(Camera *camera, Event * event) override;
    void update() override;
};

#endif // STARTSTATE_H
