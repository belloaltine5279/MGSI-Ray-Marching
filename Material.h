#ifndef MATERIAL_H
#define MATERIAL_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
using namespace glm;

class Material
{
public:
  vec4 color;
  float diffuse;
  float specular;
  float reflection;
  float roughness;

  Material() {}
  Material(vec3 col, float diff, float spec, float refl) : Material(vec4(col, 1.0f), diff, spec, refl, 0.0f) { }
  Material(vec3 col, float diff, float spec, float refl, float rough) : Material(vec4(col, 1.0f), diff, spec, refl, rough) { }
  Material(vec4 col, float diff, float spec, float refl) : Material(col, diff, spec, refl, 0.0f) { }
  Material(vec4 col, float diff, float spec, float refl, float rough)
  {
    color = col;
    diffuse = diff;
    specular = spec;
    reflection = refl;
    roughness = rough;
  }
};

#endif