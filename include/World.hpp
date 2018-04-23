#ifndef H_AW_WORLD
#define H_AW_WORLD

#include <memory>
#include "TilePlane.hpp"
#include "Scene.hpp"

namespace aw {
template <unsigned int Width, unsigned int Height, unsigned short TileSize = 16, unsigned short PixelSize = 1>
class World {

public:

    typedef TilePlane<Width, Height, TileSize, PixelSize> TilePlaneType;

    World () = default;
    ~World () = default;

    World (World&&) = default;
    World& operator = (World&&) = default;

    World (const World&) = default;
    World& operator = (const World&) = default;

private:

    std::unique_ptr<TilePlaneType> m_tilePlane;
    std::unique_ptr<Scene> m_scene;

};
}

#endif
