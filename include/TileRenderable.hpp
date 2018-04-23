#ifndef H_AW_TILERENDERABLE
#define H_AW_TILERENDERABLE

#include "Renderable.hpp"
#include "TilePlane.hpp"

namespace aw {
template <unsigned int Width, unsigned int Height, unsigned short TileSize, unsigned short PixelSize>
class TileRenderable : public Renderable {

public:

    typedef TilePlane<Width, Height, TileSize, PixelSize> TilePlaneType;

    TileRenderable () = default;
    virtual ~TileRenderable () = default;

    TileRenderable (TileRenderable&&) = default;
    TileRenderable& operator = (TileRenderable&&) = default;

    TileRenderable (const TileRenderable&) = default;
    TileRenderable& operator = (const TileRenderable&) = default;

    TilePlaneType* getTilePlane () {
        return m_tilePlane;
    }

protected:

    TilePlaneType* m_tilePlane {nullptr};

};
}

#endif
