#ifndef RENDERER_H
#define RENDERER_H
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <iostream>
#include <SDL/SDL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>


#include <string>

using namespace std;
using namespace glm;

#include "Camera.h"

class Renderer{
public:
  Renderer(int screenWidth, int screenHeight, std::string shaderBaseName);
  ~Renderer();

  void initOpenGL(std::string shaderBaseName);

  void draw(Camera& camera);
private:
  SDL_Surface* window;

  int programID;

  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo;

  int screenWidth;
  int screenHeight;

  int locCameraPosition;
  int locCameraRotation;
  int locFieldOfView;
  int locScreenSize;

  std::vector<vec3> vertices = {
    vec3(-1.0, 1.0, 0.0),
    vec3(-1.0, -1.0, 0.0),
    vec3(1.0, -1.0, 0.0),
    vec3(1.0, 1.0, 0.0)
  };
  std::vector<unsigned int> indices = {
    0, 1, 2,
    2, 3, 0
  };
};
#endif