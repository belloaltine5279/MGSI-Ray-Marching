//
// Created by bello on 21/11/2022.
//

#ifndef STARTERKITSDLSHADERCUBE_CAMERA_H
#define STARTERKITSDLSHADERCUBE_CAMERA_H
#include <GL/glew.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm ;

class Camera{
private :
    bool flag ;
    vec3 positionCamera ;
vec3 lookAt ;
//vec3 cameraHaut ;
vec3 rotation ; // x et y cameraanglex et cameraangley
vec3 translation ; // x et y et cameraDistance
vec2 FieldOfView ;
public:
    Camera();
    Camera(const vec3 &, const vec3 &, const vec2 & , const vec3 &, const vec3 &) ;
    ~Camera() ;

    void setLookAt(const vec3&) ;
    //void setUp(const vec3&) ;

    void setFieldOfView(const vec2 &);
    void setRotation(const vec3 &);
    void setPosition(const vec3 &);
    void moveCamera(const vec3 & ) ;

    vec3 getPosition() const; 
    vec2 getFieldOfView() const ; 
    vec3 getRotation() const ;
    vec3 getTranslation() const ;
    
    void move(const vec3 &) ; 

    bool ismoved(){
        return flag ;
    }
};

#endif //STARTERKITSDLSHADERCUBE_CAMERA_H
