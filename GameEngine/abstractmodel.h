#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H
#include <glm/glm.hpp>
using namespace glm;

class AbstractModel
{
public:
    AbstractModel();
    virtual ~AbstractModel();
    virtual void draw(const mat4 &view, const mat4 &projection) = 0;
};

#endif // ABSTRACTMODEL_H
