#include "scene.h"
#include "canvas.h"
#include "renderer.h"
#include <iostream>

int main() {
    Renderer r {"result.ppm"};
    Canvas cv {1000, 1000};
    Scene sc;
    LightSource ls;
    std::cout << "Light source: location (3 coordinates) and intensity\n";
    std::cin >> ls;
    sc.addLightSource(ls);
    Sphere s1, s2;
    std::cout << "Two spheres: location (3 coordinates), color (3 numbers 0-255), radius\n";
    std::cin >> s1;
    sc.addObject(s1);
    std::cin >> s2;
    sc.addObject(s2);
    cv.draw(sc);
    r.render(cv);
    return 0;
}