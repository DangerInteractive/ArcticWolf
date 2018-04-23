#ifndef H_AW_SPRITECOMPONENT
#define H_AW_SPRITECOMPONENT

#include <memory>
#include <SFML/Graphics.hpp>
#include "EntityComponent.hpp"

namespace aw {
class SpriteComponent : public EntityComponent {

public:

    SpriteComponent () = default;
    explicit SpriteComponent (sf::Sprite&&);
    SpriteComponent (Entity*, sf::Sprite&&);
    explicit SpriteComponent (const sf::Sprite&);
    SpriteComponent (Entity*, const sf::Sprite&);
    ~SpriteComponent () = default;

    SpriteComponent (SpriteComponent&&) = default;
    SpriteComponent& operator = (SpriteComponent&&) = default;

    SpriteComponent (const SpriteComponent&) = default;
    SpriteComponent& operator = (const SpriteComponent&) = default;

    sf::Sprite* getSprite ();

protected:

    sf::Sprite m_sprite;

};
}

#endif
