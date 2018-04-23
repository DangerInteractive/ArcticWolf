#include "../include/TileType.hpp"

sf::Sprite* aw::TileType::getSprite () {

    return &m_sprite;

}

bool aw::TileType::isSolid () const {

    return m_solid;

}

bool aw::TileType::isVisible () const {

    return m_visible;

}

bool aw::TileType::is (const std::string& key) const {

    return m_boolMap.at(key);

}

bool aw::TileType::get (const std::string& key) const {

    return m_doubleMap.at(key);

}

void aw::TileType::setSprite (sf::Sprite&& sprite) {

    m_sprite = std::move(sprite);

}

void aw::TileType::setSprite (const sf::Sprite& sprite) {

    m_sprite = sprite;

}

void aw::TileType::makeSolid () {

    m_solid = true;

}

void aw::TileType::makeNonsolid () {

    m_solid = false;

}

void aw::TileType::makeVisible () {

    m_visible = true;

}

void aw::TileType::makeInvisible () {

    m_visible = false;

}

void aw::TileType::setBool (const std::string& key, bool value) {

    m_boolMap[key] = value;

}

void aw::TileType::setDouble (const std::string& key, double value) {

    m_doubleMap[key] = value;

}
