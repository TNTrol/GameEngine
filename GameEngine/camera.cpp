#include "camera.h"

Camera::Camera(const vec3 &position, const vec2 &angle, const vec3 &scale)
{
    m_position = position;
    m_angle = angle;
    m_scale = scale;
}

Camera::~Camera()
{
}

vec3 Camera::getPosition()
{
    return m_position;
}

void Camera::setPosition(const vec3 &position)
{
    m_position = position;
}

vec3 Camera::getScale()
{
    return m_scale;
}

void Camera::setScale(const vec3 &scale)
{
    m_scale = scale;
}

vec2 Camera::getAngle()
{
    return m_angle;
}

void Camera::setAngle(const vec2 &angle)
{
    m_angle = angle;
    if(m_angle[0] * m_angle[0] > Pi * Pi / 4)
        m_angle[0] = m_angle[0] > 0 ? Pi/ 2 - 0.001f : -(Pi/2 - 0.001f);
    const float verticalAngle = m_angle[0];
    const float horizontalAngle = m_angle[1];
    m_direction = glm::vec3(
                cos(verticalAngle) * sin(horizontalAngle),
                sin(verticalAngle),
                cos(verticalAngle) * cos(horizontalAngle)
            );
    m_right = glm::vec3(
                sin(horizontalAngle - Pi/2.0f),
                0,
                cos(horizontalAngle - Pi/2.0f)
            );
    m_up = glm::cross( m_right, m_direction );
}

vec3 Camera::getUpVec3()
{
    return m_up;
}

vec3 Camera::getRihtVec3()
{
    return m_right;
}

vec3 Camera::getDirection()
{
    return m_direction;
}

mat4 Camera::getViewMatrix()
{
    return glm::lookAt( m_position, m_position + m_direction, m_up);
}

mat4 Camera::getPprojectionMatrix(const float aspect)
{
    glm::mat4 Projection = glm::perspective(glm::radians(m_FoV), aspect, m_near, m_far);
    return Projection;
}


