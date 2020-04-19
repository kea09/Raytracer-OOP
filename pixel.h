#pragma once
#include "vec3f.h"

class Pixel {
    private:
        Color color;
        Vec3f location; // Coordinates in units
    public:
        Pixel(const Vec3f& v);
        Pixel(const Color& c, const Vec3f& v);
        void setColor(const Color& c);
        Vec3f getLocation() const;
        Color getColor() const;
};
