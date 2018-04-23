#ifndef H_AW_TILERENDERER
#define H_AW_TILERENDERER

#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Renderer.hpp"
#include "TileRenderable.hpp"

namespace aw {
template <typename T>
class TileRenderer : public Renderer {

public:

    TileRenderer () = default;
    virtual ~TileRenderer () = default;

    TileRenderer (TileRenderer&&) = default;
    TileRenderer& operator = (TileRenderer&&) = default;

    TileRenderer (const TileRenderer&) = default;
    TileRenderer& operator = (const TileRenderer&) = default;

    virtual void render (T tile, Renderable*, double, double);

protected:

    void stamp (sf::Sprite*, double, double);

};
}

#endif
