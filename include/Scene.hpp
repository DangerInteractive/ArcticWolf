#ifndef H_AW_SCENE
#define H_AW_SCENE

#include <vector>
#include <memory>
#include "Layer.hpp"
#include "PriorityVector.hpp"

namespace aw {
class Scene {

public:

    typedef std::vector<std::unique_ptr<Layer>> LayerVector;
    typedef PriorityVector<Layer*, std::greater<Layer*>> LayerPriorityVector;

    Scene ();
    ~Scene () = default;

    Scene (Scene&&) = default;
    Scene& operator = (Scene&&) = default;

    Scene (const Scene&) = default;
    Scene& operator = (const Scene&) = default;

protected:

    LayerPriorityVector generateRenderCache () const;

    LayerVector m_layers;

    LayerPriorityVector m_renderCache;

};
}

#endif
