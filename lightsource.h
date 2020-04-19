#pragma once
#include "vec3f.h"
#include <iostream>

class LightSource {
    private:
        Vec3f location;
        float intensity;
    public:
        LightSource();
        LightSource(const Vec3f& loc, float inten);
        Vec3f getLocation() const;
        float getIntensity() const;
        friend std::istream& operator>>(std::istream& in, LightSource& ls);
};
