#ifndef SCENE_H
#define SCENE_H
#include "iostream"
#include <GL/glew.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Object.h"

using namespace std;
using namespace glm;


class Scene{
    private:
        std::vector<Object> listObjects;


    public:
        Scene();
        ~Scene();
        
        std::vector<Object> getListObjects();
        void setListObjects(std::vector<Object> objects);
        void addObject(Object object);
        void removeObject(int id);
        void updateObject(int id,Object o);
        std::vector<mat3*>  * objectsToVec4s();

 

};
#endif