#pragma once
#include "vec3f.h"
#include <iostream>

class LightSource {
    private:
        Vec3f location;
        double intensity;
    public:
        LightSource();
        LightSource(const Vec3f& loc, double inten);
        Vec3f getLocation() const;
        double getIntensity() const;
        friend std::istream& operator>>(std::istream& in, LightSource& ls);;
};
