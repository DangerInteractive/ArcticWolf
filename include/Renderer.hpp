#ifndef H_AW_RENDERER
#define H_AW_RENDERER

#include "Renderable.hpp"
#include "Layer.hpp"

namespace aw {
class Renderer {

public:

    Renderer () = default;
    virtual ~Renderer () = default;

    Renderer (Renderer&&) = default;
    Renderer& operator = (Renderer&&) = default;

    Renderer (const Renderer&) = default;
    Renderer& operator = (const Renderer&) = default;

    virtual void render (Renderable*, double cameraX, double cameraY) = 0;

protected:

    Layer* m_layer {nullptr};

};
}

#endif
