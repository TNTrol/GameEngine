#ifndef MOUSESTATE_H
#define MOUSESTATE_H

#include <abstractstate.h>



class MouseState: AbstractState
{
public:
    MouseState(AbstractState *state);
    ~MouseState() override;
    AbstractState* handle(Camera *camera, Event * event) override;
    void update() override;
private:
    AbstractState* m_state;
};

#endif // MOUSESTATE_H
