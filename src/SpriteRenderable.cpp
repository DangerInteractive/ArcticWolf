#include "../include/SpriteRenderable.hpp"

sf::Sprite* aw::SpriteRenderable::getSprite () {

    return &m_sprite;

}

void aw::SpriteRenderable::setSprite (sf::Sprite&& sprite) {

    m_sprite = std::move(sprite);

}

void aw::SpriteRenderable::setSprite (const sf::Sprite& sprite) {

    m_sprite = sprite;

}
