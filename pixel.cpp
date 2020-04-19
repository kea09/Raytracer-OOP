#include "pixel.h"

Pixel::Pixel(const Vec3f& v) : color(), location(v) {}

Pixel::Pixel(const Color& c, const Vec3f& v) : color(c), location(v) {}

void Pixel::setColor(const Color& c) {
    color = c;
}

Vec3f Pixel::getLocation() const {
    return location;
}

Color Pixel::getColor() const {
    return color;
}
