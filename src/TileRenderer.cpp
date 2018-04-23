#include "../include/TileRenderer.hpp"

void aw::TileRenderer::render (Renderable* renderable, double cameraX, double cameraY) {

    auto tileRenderable = dynamic_cast<TileRenderable>(renderable);

    if (tileRenderable == nullptr) {
        return;
    }

    auto context = Window::getContext();
    auto tilePlane = tileRenderable.getTilePlane();

    auto viewport = context->getViewport();

    auto topLeftTileX = tilePlane->subdivide(viewport.left);
    auto topLeftTileY = tilePlane->subdivide(viewport.top);

    auto bottomRightTileX = tilePlane->subdivide(viewport.left + viewport.width);
    auto bottomRightTileY = tilePlane->subdivide(viewport.top + viewport.height);

    for (unsigned int y = topLeftTileY; y < bottomRightTileY; ++y) {
        for (unsigned int x = topLeftTileX; x < bottomRightTileX; ++x) {
            stamp(tilePlane.get(x, y), renderable, );
        }
    }

}
