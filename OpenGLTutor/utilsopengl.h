#ifndef UTILSOPENGL_H
#define UTILSOPENGL_H
#include <GL/glew.h>

namespace  UtilsOpenGL{

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
GLuint loadDDS(const char * path);
}



#endif // UTILSOPENGL_H
