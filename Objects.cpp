#include "Objects.h"

Objects::Objects(  Vec3 Position,  Vec3 Color)
{
    this->Position[0]=Position[0];
    this->Position[1]=Position[1];
    this->Position[2]=Position[2];

    this->Color[0]=Color[0];
    this->Color[1]=Color[1];
    this->Color[2]=Color[2];
}
void Objects::setPosition(const Vec3& u)
{
   this->Position.set(u);
}

void Objects::getRotationOX(float angle)
{  
   this->Position[1]=this->Position[1]*cosf(angle)-this->Position[2]*sinf(angle);
   this->Position[2]=this->Position[1]*sinf(angle)+this->Position[2]*cosf(angle);
}

void Objects::getRotationOY(float angle)
{  
   this->Position[0]=this->Position[0]*cosf(angle)+this->Position[2]*sinf(angle);
   this->Position[2]=-this->Position[0]*sinf(angle)+this->Position[2]*cosf(angle);
}

void Objects::getRotationOZ(float angle)
{  
   this->Position[0]=this->Position[0]*cosf(angle)-this->Position[1]*sinf(angle);
   this->Position[1]=this->Position[0]*sinf(angle)+this->Position[1]*cosf(angle);
}


void Objects::getScale(Vec3 val)
{
  this->Position[0]=val[0]*this->Position[0];
  this->Position[1]=val[1]*this->Position[1];
  this->Position[2]=val[2]*this->Position[2];
}

void Objects::getTranslate(Vec3 val)
{
  this->Position[0]=val[0]+this->Position[0];
  this->Position[1]=val[1]+this->Position[1];
  this->Position[2]=val[2]+this->Position[2];
}

Vec3 Objects::getPosition(){return this->Position;}
Vec3 Objects::getColor(){return this->Color;}


int main()
{    Objects* B= new Objects(Vec3(1,1,1),Vec3(1,1,1));
     std::cout<<B->getPosition()<<std::endl;
     B->getRotationOX(180.0);
     std::cout<<"rotation OX  "<<B->getPosition()<<std::endl;
     B->setPosition(Vec3(1,1,1));
     B->getRotationOZ(180.0);
     std::cout<<"rotation OZ  "<<B->getPosition()<<std::endl;
     B->setPosition(Vec3(1,1,1));
     B->getRotationOY(180.0);
     std::cout<<"rotation OY   "<<B->getPosition()<<std::endl;
     B->setPosition(Vec3(1,1,1));
     B->getScale(Vec3(2,2,2));
     std::cout<<"Scale   "<<B->getPosition()<<std::endl;
     B->setPosition(Vec3(1,1,1));
     B->getTranslate(Vec3(-1,-1,-1));
     std::cout<<"Translate   "<<B->getPosition()<<std::endl;
    return 0;
}