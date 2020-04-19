#pragma once
#include "scene.h"
#include "pixel.h"
#include <vector>

/* 
 * Assumes the canvas is 1 unit in both directions an 1 unit away from camera
 */ 
class Canvas {
    private:
        std::vector<Pixel> grid;
        int width;
        int height;
    public:
        Canvas(int width, int height);
        void draw(const Scene& sc);
        Pixel& operator[](int i);
        const Pixel& operator[](int i) const;
        int getWidth() const;
        int getHeight() const;
};
