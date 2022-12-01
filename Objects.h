#include "Vec3.cpp"
class Objects
{
   public:
      Objects(  Vec3,  Vec3);
      Vec3 Position;//position
      Vec3 Color;//color
      void setPosition(const Vec3&);
      void setCouleur(const Vec3&);
      void getRotationOX(float angle);
      void getRotationOY(float angle);
      void getRotationOZ(float angle);
      void getTranslate(const Vec3);
      void getScale( const Vec3 );
      Vec3 getPosition();
      Vec3 getColor(); 
      virtual bool  Intersection();
    };