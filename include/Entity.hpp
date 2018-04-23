#ifndef H_AW_ENTITY
#define H_AW_ENTITY

#include <memory>
#include "Layer.hpp"
#include "Scene.hpp"

namespace aw {
class Entity {

public:

    Entity () = default;
    ~Entity () = default;

    Entity (Entity&&) = default;
    Entity& operator = (Entity&&) = default;

    Entity (const Entity&) = default;
    Entity& operator = (const Entity&) = default;

    Layer* getLayer () const;
    Scene* getScene () const;

protected:

    Layer* m_layer {nullptr};

};
}

#endif
