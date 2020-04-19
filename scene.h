#pragma once
#include <vector>
#include "object.h"
#include "lightsource.h"

class Scene {
    private:
        std::vector<Object*> objects;
        std::vector<LightSource> vls;
    public:
        Scene();
        Color castRay(const Vec3f& ray) const;
        void addObject(Object& obj);
        void addLightSource(const LightSource& ls);
};