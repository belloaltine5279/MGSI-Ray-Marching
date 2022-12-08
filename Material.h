#ifndef MATERIAL_H
#define MATERIAL_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
using namespace glm;

class Material
{
public:
  vec3 color;
  float diffuse;
  float specular;
  float reflection;

  Material() {}
  Material(vec3 col, float diff, float spec, float refl)
  {
    color = col;
    diffuse = diff;
    specular = spec;
    reflection = refl;
  }
};

#endif