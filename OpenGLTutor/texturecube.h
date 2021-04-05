#ifndef TEXTURECUBE_H
#define TEXTURECUBE_H

#include <abstractmodel.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class TextureCube: public AbstractModel
{
public:
    TextureCube();
    ~TextureCube() override;
    void draw(const mat4 &view, const mat4 &projection) override;
protected:
    GLuint m_programID;
    GLuint m_VBO;
    GLuint m_UVBO;
    GLuint m_matrixID;
    GLuint m_texture;
    GLuint m_textureID;
    GLuint VertexArrayID;
};

#endif // TEXTURECUBE_H
