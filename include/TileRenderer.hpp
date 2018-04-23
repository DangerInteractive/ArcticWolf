#ifndef H_AW_TILERENDERER
#define H_AW_TILERENDERER

#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Renderer.hpp"
#include "TileRenderable.hpp"
#include "TileSet.hpp"

namespace aw {
template <unsigned int Width, unsigned int Height, unsigned short TileSize, unsigned short PixelSize>
class TileRenderer : public Renderer {

public:

    typedef TileRenderable<Width, Height, TileSize, PixelSize> TileRenderableType;
    typedef TilePlane<Width, Height, TileSize, PixelSize> TilePlaneType;

    TileRenderer () = default;
    virtual ~TileRenderer () = default;

    TileRenderer (TileRenderer&&) = default;
    TileRenderer& operator = (TileRenderer&&) = default;

    TileRenderer (const TileRenderer&) = default;
    TileRenderer& operator = (const TileRenderer&) = default;

    virtual void render (Renderable*, double, double) {}

    virtual void render (TileRenderableType* renderable, double cameraX, double cameraY) {

        if (renderable == nullptr) {
            return;
        }

        auto context = Window::getContext();
        TilePlaneType* tilePlane = renderable->getTilePlane();

        auto size = context->getSize();

        double centerX = size.x * 0.5;
        double centerY = size.y * 0.5;

        double topLeftCoordinateX = cameraX - centerX;
        double topLeftCoordinateY = cameraY - centerY;

        double bottomRightCoordinateX = cameraX + centerX;
        double bottomRightCoordinateY = cameraY + centerY;

        auto topLeftTileX = tilePlane->subdivide(topLeftCoordinateX);
        auto topLeftTileY = tilePlane->subdivide(topLeftCoordinateY);

        auto bottomRightTileX = tilePlane->subdivide(bottomRightCoordinateX);
        auto bottomRightTileY = tilePlane->subdivide(bottomRightCoordinateY);

        double topLeftTileTopLeftCoordinateX = tilePlane->superdivide(topLeftTileX);
        double topLeftTileTopLeftCoordinateY = tilePlane->superdivide(topLeftTileY);

        for (unsigned int y = topLeftTileY; y < bottomRightTileY; ++y) {
            for (unsigned int x = topLeftTileX; x < bottomRightTileX; ++x) {
                stamp(tilePlane->get(x, y), topLeftTileTopLeftCoordinateX - topLeftCoordinateX, topLeftTileTopLeftCoordinateY - topLeftCoordinateY);
            }
        }

    }

protected:

    void stamp (TilePlaneType* plane, unsigned int x, unsigned int y, double atX, double atY) {

        auto context = Window::getContext();
        if (context == nullptr) { return; }
        auto tileType = plane->getTileType(x, y);
        if (tileType == nullptr) { return; }
        auto sprite = tileType->getSprite();
        if (sprite == nullptr) { return; }

        sprite->setPosition(atX, atY);
        context->draw(sprite);

    }

};
}

#endif
