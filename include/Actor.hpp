#ifndef H_AW_ACTOR
#define H_AW_ACTOR

#include <memory>
#include "Layer.hpp"
#include "Scene.hpp"

namespace aw {
class Actor {

public:

    Actor () = default;
    ~Actor () = default;

    Actor (Actor&&) = default;
    Actor& operator = (Actor&&) = default;

    Actor (const Actor&) = default;
    Actor& operator = (const Actor&) = default;

    Layer* getLayer () const;
    Scene* getScene () const;

protected:

    Layer* m_layer {nullptr};

};
}

#endif
