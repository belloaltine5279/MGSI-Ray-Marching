//
// Created by bello on 23/11/2022.
//
#include "Camera.h"

using namespace std;
using namespace glm;

Camera::Camera(){

    flag = false ;
    // si on change de position initial dans la fonction setPosition
    // dans la fonction moveCamera on change la valeur
    // flag par true ;
}

Camera::~Camera(){

}
Camera::Camera(const vec3 &cameraPosition, const vec3 &rotation,
               const vec2 &FieldOfView, const vec3 &translation ,
               const vec3 &lookat) {
    this->positionCamera = cameraPosition ;
    this->rotation = rotation ;
    this->FieldOfView = FieldOfView ;
    this->translation = translation ;
    this->lookAt = lookat;
}

void Camera::setFieldOfView(const vec2 &a) {
    this->FieldOfView = a ;
    flag = true ;
}

void Camera::setPosition(const vec3 &a) {
    this->positionCamera = a ;
    flag = true ;
}

void Camera::setRotation(const vec3 &a) {
    this->rotation = a ;
    flag = true ;
}

void Camera::move(const vec3 &m){
    this->positionCamera + m ;
    this->flag = true ; // pour declancher que la camera a ete bouger
}

vec2 Camera::getFieldOfView() const {
    return this->FieldOfView ; // avoir le champ de vision de la camera
}

vec3 Camera::getPosition() const {
    return this->positionCamera;
}
vec3 Camera::getRotation() const {
    return this->rotation;
}
vec3 Camera::getTranslation() const {
    return this->translation ;
}