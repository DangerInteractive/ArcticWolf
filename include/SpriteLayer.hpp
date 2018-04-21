#ifndef H_CLASS_SPRITELAYER
#define H_CLASS_SPRITELAYER

#include <map>
#include "Layer.hpp"
#include "Sprite.hpp"

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

    std::map<int, Sprite> m_sprite;

};
}

#endif
