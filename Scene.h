#ifndef SCENE_H
#define SCENE_H

#include "iostream"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <vector>

#include "CSG.h"
#include "Object.h"

using namespace std;
using namespace glm;


class Scene{
    private:
        std::vector<Object*> listObjects;

    public:
        Scene();
        ~Scene();
        
        std::vector<Object*> getListObjects();
        void setListObjects(std::vector<Object*> objects);
        void addObject(Object* object);
        void removeObject(int id);
        void updateObject(int id,Object* o);
        std::vector<mat4> objectsToVec4s();
        void getInfos(vector<mat4>& objectMatrices, vector<Material>& objectMaterials, vector<int>& objectTypes, vector<float>& objectDatas, 
    vector<int>& csg_types, vector<float>& csg_values);

    private:
        void reccursiveInfos(CSG& csg_actuel,
            vector<mat4>& objectMatrices, vector<Material>& objectMaterials, vector<int>& objectTypes, vector<float>& objectDatas, 
            vector<int>& csg_types, vector<float>& csg_values);
};

#endif