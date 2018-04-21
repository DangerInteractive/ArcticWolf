#ifndef H_CLASS_GRIDLAYER
#define H_CLASS_GRIDLAYER

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
