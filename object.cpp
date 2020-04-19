#include "object.h"
#include <cmath>
#include <limits>

Object::Object() : location(), color() {}

Object::Object(const Vec3f& v, const Color& c) : location(v), color(c) {}

Vec3f Object::getlocation() const {
    return location;
}

Color Object::getColor() const {
    return color;
}

std::istream& operator>>(std::istream& in, Object& obj) {
    in >> obj.location >> obj.color;
    return in;
}

Sphere::Sphere() : Object(), radius(0) {}

Sphere::Sphere(const Vec3f& v, const Color& c, float r) : Object(v, c), radius(r) {}

void Sphere::checkRay(const Vec3f& origin, const Vec3f& direction, float& t1, float& t2) const {
    Vec3f oc = origin - location;
    
    float k1 = direction * direction;
    float k2 = 2 * oc * direction;
    float k3 = oc * oc - radius * radius;

    float d = k2 * k2 - 4 * k1 * k3;
    if (d < 0) {
        t1 = t2 = std::numeric_limits<float>::infinity();
        return;
    }

    t1 = (-k2 + sqrt(d)) / (2*k1);
    t2 = (-k2 - sqrt(d)) / (2*k1);
}

Vec3f Sphere::getNormalVector(const Vec3f& v) const {
    Vec3f norm = v - location;
    norm.normalize();
    return norm;
}

std::istream& operator>>(std::istream& in, Sphere& sph) {
    in >> sph.location >> sph.color >> sph.radius;
    return in;
}
