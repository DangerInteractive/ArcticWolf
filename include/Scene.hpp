#ifndef H_CLASS_SCENE
#define H_CLASS_SCENE

#include <map>
#include "Layer.hpp"

namespace aw {
class Scene {

public:

    Scene () = default;
    ~Scene () = default;

    Scene (Scene&&) = default;
    Scene& operator = (Scene&&) = default;

    Scene (const Scene&) = default;
    Scene& operator = (const Scene&) = default;

private:

    std::map<int, Layer> m_layers;

};
}

#endif
