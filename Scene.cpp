#include "Scene.h"

Scene::Scene(){


}

Scene::~Scene(){

}
void Scene::setListObjects(std::vector<Object> objects){
    this->listObjects = objects;
}
std::vector<Object> Scene::getListObjects(){
    return this->listObjects;
}
void Scene::addObject(Object object){
    this->listObjects.push_back(object);
}
void Scene::updateObject(int id,Object o){
    this->listObjects.at(id) = o;
}
void Scene::removeObject(int id){
    this->listObjects.erase(this->listObjects.begin(),this->listObjects.begin()+id);
}
std::vector<mat3*> * Scene::objectsToVec4s(){
    std::vector<mat3*> * mat3s = new std::vector<mat3*>();

    vector<Object>::iterator it;
    int i = 0;
    for(it = this->listObjects.begin(); it != this->listObjects.end(); it++,i++ )    {
        Object o = *it;
        
        mat3 * mat = new mat3(o.getPosition(),o.getRotation(),o.getScale());
        mat3s->push_back(mat);

    }


    return mat3s;
}


int main(){

    Scene * s = new Scene();
    
}