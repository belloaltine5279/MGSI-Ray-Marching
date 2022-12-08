#ifndef OBJECT_H
#define OBJECT_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
using namespace glm;

#include <vector>

#include "Material.h"

class Object
{
   public:
      vec3 position;//position
      vec3 rotation;//position
      vec3 scale;//position
      Material material;//color

      Object(vec3, vec3, vec3, Material& material);
      void setPosition(const vec3&);
      void setRotation(const vec3&);
      void setScale(const vec3&);
      void setMaterial(Material&);
      //void getRotationOX(float angle);
      //void getRotationOY(float angle);
      //void getRotationOZ(float angle);
      //void getTranslate(const vec3);
      //void getScale( const vec3 );
      vec3 getPosition();
      vec3 getRotation();
      vec3 getScale();
      Material& getMaterial();
      //virtual bool  Intersection();

      //Retourne le type sous forme d'int et rempli le tableau de donnees suivant 
      //les informations necessaire a l'affichage de ce type d'objet precis
      //les autres informations comme la position ou le materiel sont deja traitees ailleurs
      virtual int getTypeData(std::vector<float>& data) = 0;
};

#endif