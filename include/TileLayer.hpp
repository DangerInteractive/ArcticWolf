#ifndef H_AW_TILELAYER
#define H_AW_TILELAYER

#include "Layer.hpp"

namespace aw {
class TileLayer : public Layer {

public:

    TileLayer () = default;
    ~TileLayer () = default;

    TileLayer (TileLayer&&) = default;
    TileLayer& operator = (TileLayer&&) = default;

    TileLayer (const TileLayer&) = default;
    TileLayer& operator = (const TileLayer&) = default;

protected:

};
}

#endif
