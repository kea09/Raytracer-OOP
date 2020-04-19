#include "scene.h"
#include "canvas.h"
#include "renderer.h"
#include <iostream>

int main() {
    Renderer r {"result.ppm"};
    Canvas cv {1280, 720};
    // Scene sc;
    // LightSource ls;
    // std::cin >> ls;
    // sc.addLightSource(ls);
    // Sphere s;
    // std::cin >> s;
    // sc.addObject(s);
    // std::cin >> s;
    // sc.addObject(s);
    // cv.draw(sc);
    r.render(cv);
    return 0;
}