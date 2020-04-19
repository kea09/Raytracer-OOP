#include "scene.h"
#include <limits>
#include <iostream>
using std::size_t;

Scene::Scene() {}

Color Scene::castRay(const Vec3f& ray) const {
    float closest = std::numeric_limits<float>::infinity();
    const Object* closestobject = nullptr;
    for (const Object* obj: objects) {
        std::vector<float> ch = obj->checkRay(Vec3f(), ray);
        for (float k: ch) {
            if (k > 1.f && k < closest) {
                closest = k;
                closestobject = obj;
            }
        }
    }

    if (closestobject == nullptr)
        return Color();
    return closestobject->getColor();
}

void Scene::addObject(Object& obj) {
    objects.push_back(&obj);
}

void Scene::addLightSource(const LightSource& ls) {
    vls.push_back(ls);
}
