#ifndef H_AW_RENDERER
#define H_AW_RENDERER

#include "Renderable.hpp"
#include "Layer.hpp"

namespace aw {
class Renderer {

public:

    Renderer () = default;
    virtual ~Renderer () = 0;

    Renderer (Renderer&&) = default;
    Renderer& operator = (Renderer&&) = default;

    Renderer (const Renderer&) = default;
    Renderer& operator = (const Renderer&) = default;

    virtual void render (Renderable*, double cameraX, double cameraY);

protected:

    Layer* m_layer {nullptr};

};
}

#endif
