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
Camera::Camera(const vec3 &position, const vec3 &rotation,
               const vec2 &fieldOfView //, const vec3 &translation ,
               //const vec3 &lookat
               ) {
    this->position = position ;
    this->rotation = rotation ;
    this->fieldOfView = fieldOfView ;
    //this->translation = translation ;
    //this->lookAt = lookat;
}

void Camera::setFieldOfView(const vec2 &a) {
    this->fieldOfView = a ;
    flag = true ;
}

void Camera::setPosition(const vec3 &a) {
    this->position = a ;
    flag = true ;
}

void Camera::setRotation(const vec3 &a) {
    this->rotation = a ;
    flag = true ;
}

void Camera::move(const vec3 &m){
    this->position + m ;
    this->flag = true ; // pour declancher que la camera a ete bouger
}

void Camera::rotateX(const float &amount){
    this->rotation.x += amount;
    if (amount != 0.0f) this->flag = true;
}
void Camera::rotateY(const float &amount){
    this->rotation.y += amount;
    if (amount != 0.0f) this->flag = true;
}
void Camera::rotateZ(const float &amount){
    this->rotation.z += amount;
    if (amount != 0.0f) this->flag = true;
}

vec2 Camera::getFieldOfView() const {
    return this->fieldOfView ; // avoir le champ de vision de la camera
}

vec3 Camera::getPosition() const {
    return this->position;
}
vec3 Camera::getRotation() const {
    return this->rotation;
}
//vec3 Camera::getTranslation() const {
//    return this->translation ;
//}