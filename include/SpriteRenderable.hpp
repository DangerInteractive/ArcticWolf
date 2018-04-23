#ifndef H_AW_SPRITERENDERABLE
#define H_AW_SPRITERENDERABLE

#include <SFML/Graphics.hpp>
#include "Renderable.hpp"

namespace aw {
class SpriteRenderable : public Renderable {

public:

    SpriteRenderable () = default;
    virtual ~SpriteRenderable () = default;

    SpriteRenderable (SpriteRenderable&&) = default;
    SpriteRenderable& operator = (SpriteRenderable&&) = default;

    SpriteRenderable (const SpriteRenderable&) = default;
    SpriteRenderable& operator = (const SpriteRenderable&) = default;

    virtual sf::Sprite* getSprite ();

    virtual void setSprite (sf::Sprite&&);
    virtual void setSprite (const sf::Sprite&);

protected:

    sf::Sprite m_sprite;

};
}

#endif
