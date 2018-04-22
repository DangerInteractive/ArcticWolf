#ifndef H_AW_SPRITECOMPONENT
#define H_AW_SPRITECOMPONENT

#include <memory>
#include <SFML/Graphics.hpp>
#include "RenderComponent.hpp"

namespace aw {
class SpriteComponent : public RenderComponent {

public:

    SpriteComponent () = default;
    ~SpriteComponent () = default;

    SpriteComponent (SpriteComponent&&) = default;
    SpriteComponent& operator = (SpriteComponent&&) = default;

    SpriteComponent (const SpriteComponent&) = default;
    SpriteComponent& operator = (const SpriteComponent&) = default;

protected:

    std::shared_ptr<sf::Image> m_texture;

};
}

#endif
