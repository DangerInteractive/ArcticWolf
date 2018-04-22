#ifndef H_AW_GRIDLAYER
#define H_AW_GRIDLAYER

#include "Layer.hpp"

namespace aw {
class GridLayer : public Layer {

public:

    GridLayer () = default;
    ~GridLayer () = default;

    GridLayer (GridLayer&&) = default;
    GridLayer& operator = (GridLayer&&) = default;

    GridLayer (const GridLayer&) = default;
    GridLayer& operator = (const GridLayer&) = default;

protected:

};
}

#endif
