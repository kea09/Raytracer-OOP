#include "scene.h"
#include <limits>
#include <iostream>
using std::size_t;

Scene::Scene() {}

Color Scene::castRay(const Vec3f& ray) const {
    Color c (255);
    c = c * ls.getIntensity();
    Vec3f dir(ray);
    dir.normalize();
    float closest = std::numeric_limits<float>::infinity();
    const Object* closestobject = nullptr;
    for (const Object* obj: objects) {
        float t1, t2;
        obj->checkRay(Vec3f(), dir, t1, t2);
        if (t1 > 1.f && t1 < closest) {
            closest = t1;
            closestobject = obj;
        }
        if (t2 > 1.f && t2 < closest) {
            closest = t2;
            closestobject = obj;
        }
    }

    if (closestobject != nullptr) {
        c = closestobject->getColor();
        Vec3f p = closest * dir;
        Vec3f norm = closestobject->getNormalVector(p);
        c = c * ls.getIntensity(p, norm);
    }
    return c;
}

void Scene::addObject(Object& obj) {
    objects.push_back(&obj);
}

void Scene::addLightSource(const LightSource& ls) {
    this->ls = ls;
}
