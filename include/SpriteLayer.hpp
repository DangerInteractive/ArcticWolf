#ifndef H_AW_SPRITELAYER
#define H_AW_SPRITELAYER

#include <map>
#include "Layer.hpp"
#include "SpriteComponent.hpp"

namespace aw {
class SpriteLayer : public Layer {

public:

    SpriteLayer () = default;
    ~SpriteLayer () = default;

    SpriteLayer (SpriteLayer&&) = default;
    SpriteLayer& operator = (SpriteLayer&&) = default;

    SpriteLayer (const SpriteLayer&) = default;
    SpriteLayer& operator = (const SpriteLayer&) = default;

protected:

    std::map<int, SpriteComponent*> m_sprite;

};
}

#endif
