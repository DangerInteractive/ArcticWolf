#ifndef H_AW_SCENE
#define H_AW_SCENE

#include <unordered_map>
#include <memory>
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

    std::unordered_map<int, std::unique_ptr<Layer>> m_layers;

};
}

#endif
