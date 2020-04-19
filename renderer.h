#pragma once
#include "canvas.h"

class Renderer {
    private:
        std::string filename;
    public:
        Renderer(std::string filename);
        void render(const Canvas& cv);
};
