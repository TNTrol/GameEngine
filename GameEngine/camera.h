#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
using namespace glm;
#define Pi 3.14f

class Camera
{
public:
    Camera(const vec3 &position = vec3(0,0,0), const vec2 &angle = vec2(0,Pi), const vec3 &scale = vec3(1,1,1));
    ~Camera();
    vec3 getPosition();
    void setPosition(const vec3 &position);
    vec3 getScale();
    void setScale(const vec3 &scale);
    vec2 getAngle();
    void setAngle(const vec2 &angle);
    vec3 getUpVec3();
    vec3 getRihtVec3();
    vec3 getDirection();
    mat4 getViewMatrix();
    mat4 getPprojectionMatrix(const float aspect);
protected:
    vec3 m_position;
    vec3 m_scale;
    vec3 m_direction;
    vec3 m_up;
    vec3 m_right;
    vec2 m_angle;
    float m_near = 0.1f;
    float m_far = 100.0f;
    float m_FoV = 50.0f;
};

#endif // CAMERA_H
