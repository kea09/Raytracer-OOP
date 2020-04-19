#include "lightsource.h"
using std::size_t;

LightSource::LightSource() : location(), intensity(1) {}

LightSource::LightSource(const Vec3f& v, float i) : location(v), intensity(i) {}

Vec3f LightSource::getLocation() const {
    return location;
}

float LightSource::getIntensity() const {
    return intensity;
}

float LightSource::getIntensity(const Vec3f& p, const Vec3f& n) const {
    float i = 0;
    Vec3f l = location - p;
    float nl = n * l;
    if (nl > 0)
        i = intensity * nl / n.length() / l.length();
    return i;
}

std::istream& operator>>(std::istream& in, LightSource& ls) {
    in >> ls.location >> ls.intensity;
    return in;
}