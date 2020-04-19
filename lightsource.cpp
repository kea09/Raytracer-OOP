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

std::istream& operator>>(std::istream& in, LightSource& ls) {
    in >> ls.location >> ls.intensity;
    return in;
}