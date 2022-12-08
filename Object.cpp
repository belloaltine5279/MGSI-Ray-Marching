#include "Object.h"

Object::Object(vec3 position, vec3 rotation, vec3 scale, Material& material)
{
   this->position = position;
   this->rotation = rotation;
   this->scale = scale;

   this->material = material;
}

void Object::setPosition(const vec3& u) { this->position = u; }
void Object::setRotation(const vec3& u) { this->rotation = u; }
void Object::setScale(const vec3& u) { this->scale = u; }
void Object::setMaterial(Material& m) { this->material = m; }

vec3 Object::getPosition(){return this->position;}
vec3 Object::getRotation(){return this->rotation;}
vec3 Object::getScale(){return this->scale;}

Material& Object::getMaterial(){return this->material;}


/*
void Object::setRotationOX(float angle)
{  
   this->Position[1]=this->Position[1]*cosf(angle)-this->Position[2]*sinf(angle);
   this->Position[2]=this->Position[1]*sinf(angle)+this->Position[2]*cosf(angle);
}

void Object::setRotationOY(float angle)
{  
   this->Position[0]=this->Position[0]*cosf(angle)+this->Position[2]*sinf(angle);
   this->Position[2]=-this->Position[0]*sinf(angle)+this->Position[2]*cosf(angle);
}

void Object::setRotationOZ(float angle)
{  
   this->Position[0]=this->Position[0]*cosf(angle)-this->Position[1]*sinf(angle);
   this->Position[1]=this->Position[0]*sinf(angle)+this->Position[1]*cosf(angle);
}

void Object::getScale(vec3 val)
{
  this->Position[0]=val[0]*this->Position[0];
  this->Position[1]=val[1]*this->Position[1];
  this->Position[2]=val[2]*this->Position[2];
}

void Object::getTranslate(vec3 val)
{
  this->Position[0]=val[0]+this->Position[0];
  this->Position[1]=val[1]+this->Position[1];
  this->Position[2]=val[2]+this->Position[2];
}


int main()
{    Object* B= new Object(vec3(1,1,1),vec3(1,1,1));
     std::cout<<B->getPosition()<<std::endl;
     B->getRotationOX(180.0);
     std::cout<<"rotation OX  "<<B->getPosition()<<std::endl;
     B->setPosition(vec3(1,1,1));
     B->getRotationOZ(180.0);
     std::cout<<"rotation OZ  "<<B->getPosition()<<std::endl;
     B->setPosition(vec3(1,1,1));
     B->getRotationOY(180.0);
     std::cout<<"rotation OY   "<<B->getPosition()<<std::endl;
     B->setPosition(vec3(1,1,1));
     B->getScale(vec3(2,2,2));
     std::cout<<"Scale   "<<B->getPosition()<<std::endl;
     B->setPosition(vec3(1,1,1));
     B->getTranslate(vec3(-1,-1,-1));
     std::cout<<"Translate   "<<B->getPosition()<<std::endl;
    return 0;
}
*/