#include "renderer.h"
#include <fstream>
using std::ofstream;
using std::size_t;

Renderer::Renderer(std::string filename) : filename(filename) {};

void Renderer::render(const Canvas& cv) {
    ofstream out;
    out.open(filename);
    int width = cv.getWidth();
    int height = cv.getHeight();
    out << "P6\n" << width << " " << height << "\n255\n";
    size_t size = width * height;
    for (size_t i = 0; i < size; i++) {
        out << cv[i].getColor();
    }
    out.close();
}