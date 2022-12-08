#include "Scene.h"

Scene::Scene(){


}

Scene::~Scene(){

}
void Scene::setListObjects(std::vector<Object*> objects){
    this->listObjects = objects;
}
std::vector<Object*> Scene::getListObjects(){
    return this->listObjects;
}
void Scene::addObject(Object* object){
    this->listObjects.push_back(object);
}
void Scene::updateObject(int id,Object* o){
    this->listObjects.at(id) = o;
}
void Scene::removeObject(int id){
    this->listObjects.erase(this->listObjects.begin(),this->listObjects.begin()+id);
}
std::vector<mat4> Scene::objectsToVec4s(){
    std::vector<mat4> res;

    //vector<Object>::iterator it;
    //int i = 0;
    //for(it = this->listObjects.begin(); it != this->listObjects.end(); it++,i++ )    {
    for (auto o : this->listObjects) {
        mat4 t = translate(mat4(), o->getPosition());
        mat4 r = 
            rotate(mat4(), o->getRotation().x, vec3(1.0f, 0.0f, 0.0f)) *
            rotate(mat4(), o->getRotation().y, vec3(0.0f, 1.0f, 0.0f)) *
            rotate(mat4(), o->getRotation().z, vec3(0.0f, 0.0f, 1.0f));
        mat4 s = scale(mat4(), o->getScale());
        //mat3 * mat = new mat3(o.getPosition(),o.getRotation(),o.getScale());
        //mat3s.push_back(mat);
        res.push_back(t * r * s);
    }

    return res;
}