#include "canvas.h"
using std::size_t;
Canvas::Canvas(int w, int h) : width(w), height(h) {
    for (size_t i = 0; i < w; i++) {
        for (size_t j = 0; j < h; j++) {
            Vec3f v;
            v[0] = i * 2 / w - 1;
            v[1] = - j * 2 / h - 1;
            v[2] = 1;
            grid.push_back(Pixel(v));
        }
    }
}

void Canvas::draw(const Scene& sc) const {

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
