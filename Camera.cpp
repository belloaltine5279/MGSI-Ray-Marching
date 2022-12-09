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
    this->position += m ;
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

mat4 Camera::getRotationMatrix() const {
    vec3 rotation = getRotation();
    mat4 rotationMatrix(1.0);
    rotationMatrix = rotate(mat4(1.0f), rotation.z, vec3(0.0f, 0.0f, 1.0f)) *
            rotate(mat4(1.0f), rotation.y, vec3(0.0f, 1.0f, 0.0f)) *
            rotate(mat4(1.0f), rotation.x, vec3(1.0f, 0.0f, 0.0f));
    return rotationMatrix;
}

vec3 Camera::getForward() const {
    vec4 forward(0.0f, 0.0f, 1.0f, 1.0f);
    forward = getRotationMatrix() * forward;
    return vec3(forward.x, forward.y, forward.z);
}
vec3 Camera::getRight() const {
    vec4 right(1.0f, 0.0f, 0.0f, 1.0f);
    right = getRotationMatrix() * right;
    return vec3(right.x, right.y, right.z);
}
vec3 Camera::getUp() const {
    vec4 up(0.0f, 1.0f, 0.0f, 1.0f);
    up = getRotationMatrix() * up;
    return vec3(up.x, up.y, up.z);
}
//vec3 Camera::getTranslation() const {
//    return this->translation ;
//}