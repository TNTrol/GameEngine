#include <glm/glm.hpp>
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <camera.h>
#include <controller.h>
#include <cubemodel.h>
#include <iostream>

#include <startstate.h>
#include <texturecube.h>
#include <utilsopengl.h>
#include <glm/gtx/quaternion.hpp>

using namespace std;


int main() {
    //StartState start;
  Camera camera;
  //MainGameWindow maineGameWindow(1024, 768);
  Controller window(&camera, new StartState(), 1024, 768);
  TextureCube cube;
  vector<AbstractModel *> models;
  models.push_back(&cube);
  window.run(models);
  return 0;
}
