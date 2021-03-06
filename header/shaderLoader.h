#ifndef _SHADERLOADER_GUARD
#define _SHADERLOADER_GUARD

#include <stdbool.h>

#include "glew.h"

#define VERTEX_SHADER 0
#define FRAGMENT_SHADER 1

//bool createProgram(unsigned int* program, int vert, int frag);

bool initProgram(GLuint* program, const char* vertexShaderFile, const char* fragmentShaderFile);
//bool initShader(int* shaderID, unsigned int type, const char* chemin);

#endif // SHADERLOADER
