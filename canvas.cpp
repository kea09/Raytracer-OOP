#include "canvas.h"
#include <iostream>
using std::cout;
using std::endl;
using std::size_t;
Canvas::Canvas(int w, int h) : width(w), height(h) {
    for (size_t j = 0; j < h; j++) {
        for (size_t i = 0; i < w; i++) {        
            Vec3f v;
            v[0] = i * 2.f / w - 1;
            v[1] = (-1.f) * j * 2.f / h + 1;
            v[2] = 1;
            grid.push_back(Pixel(v));
        }
    }
}

void Canvas::draw(const Scene& sc) {
    for (Pixel& p: grid) {
        p.setColor(sc.castRay(p.getLocation()));
    }
}

Pixel& Canvas::operator[](int i) {
    return grid[i];
}

const Pixel& Canvas::operator[](int i) const {
    return grid[i];
}

int Canvas::getWidth() const {
    return width;
}

int Canvas::getHeight() const {
    return height;
}
