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

Sphere::Sphere(const Vec3f& v, const Color& c, double r) : Object(v, c), radius(r) {}

std::vector<float> Sphere::checkRay(const Vec3f& origin, const Vec3f& direction) const {
    Vec3f oc = origin - location;
    float k1 = direction * direction;
    float k2 = 2 * (oc * direction);
    float k3 = oc * oc - radius * radius;
    float d = k2 * k2 - 4 * k1 * k3;
    std::vector<float> x;
    if (d < 0) {
        x.push_back(std::numeric_limits<float>::infinity());
        x.push_back(std::numeric_limits<float>::infinity());
        return x;
    }
    x.push_back((-k2 - sqrt(d)) / 2 / k1);
    x.push_back((-k2 + sqrt(d)) / 2 / k1);
    return x;
}

Vec3f Sphere::getNormalVector(const Vec3f& v) const {

}

std::istream& operator>>(std::istream& in, Sphere& sph) {
    in >> sph.location >> sph.color >> sph.radius;
    return in;
}
