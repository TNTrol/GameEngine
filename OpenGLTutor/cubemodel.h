#ifndef CUBEMODEL_H
#define CUBEMODEL_H

#include <abstractmodel.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class CubeModel: public AbstractModel
{
public:
    CubeModel();
    ~CubeModel() override;
    void draw(const mat4 &view, const mat4 &projection) override;
protected:
    GLuint m_programID;
    GLuint m_VBO;
    GLuint m_CBO;
    GLuint m_matrixID;
};

#endif // CUBEMODEL_H
