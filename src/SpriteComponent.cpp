#include "../include/SpriteComponent.hpp"

aw::SpriteComponent::SpriteComponent (sf::Sprite&& sprite)
: m_sprite(sprite) {}

aw::SpriteComponent::SpriteComponent (Entity* entity, sf::Sprite&& sprite)
: EntityComponent(entity), m_sprite(std::move(sprite)) {}

aw::SpriteComponent::SpriteComponent (const sf::Sprite& sprite)
: m_sprite(sprite) {}

aw::SpriteComponent::SpriteComponent (Entity* entity, const sf::Sprite& sprite)
: EntityComponent(entity), m_sprite(sprite) {}

sf::Sprite* aw::SpriteComponent::getSprite () {

    return &m_sprite;

}
