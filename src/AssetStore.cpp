#include "../include/AssetStore.hpp"

bool aw::AssetStore::imageExists (const std::string& key) {

    if (m_images.find(key) == m_images.end()) {
        return false;
    } else {
        return true;
    }

}

std::shared_ptr<sf::Image> aw::AssetStore::getImage (const std::string& key) {

    if (!imageExists(key)) {
        return nullptr;
    }

    return m_images[key];

}

bool aw::AssetStore::registerImage (const std::string& key, const std::shared_ptr<sf::Image>& image) {

    if (imageExists(key)) {
        return false;
    }

    m_images.insert(std::pair<std::string, std::shared_ptr<sf::Image>>(key, image));
    return true;

}

bool aw::AssetStore::registerImage (const std::string& key, sf::Image* image) {

    return registerImage(key, std::shared_ptr<sf::Image>(image));

}

void aw::AssetStore::deleteImage (const std::string& key) {

    if (!imageExists(key)) {
        return;
    }

    m_images[key].reset();
    m_images.erase(key);

}

bool aw::AssetStore::soundExists (const std::string& key) {

    if (m_sounds.find(key) == m_sounds.end()) {
        return false;
    } else {
        return true;
    }

}

std::shared_ptr<sf::Sound> aw::AssetStore::getSound (const std::string& key) {

    if (!soundExists(key)) {
        return nullptr;
    }

    return m_sounds[key];

}

bool aw::AssetStore::registerSound (const std::string& key, const std::shared_ptr<sf::Sound>& sound) {

    if (soundExists(key)) {
        return false;
    }

    m_sounds.insert(std::pair<std::string, std::shared_ptr<sf::Sound>>(key, sound));
    return true;

}

bool aw::AssetStore::registerSound (const std::string& key, sf::Sound* sound) {

    return registerSound(key, std::shared_ptr<sf::Sound>(sound));

}

void aw::AssetStore::deleteSound (const std::string& key) {

    if (!soundExists(key)) {
        return;
    }

    m_sounds[key].reset();
    m_sounds.erase(key);

}

bool aw::AssetStore::fontExists (const std::string& key) {

    if (m_fonts.find(key) == m_fonts.end()) {
        return false;
    } else {
        return true;
    }

}

std::shared_ptr<sf::Font> aw::AssetStore::getFont (const std::string& key) {

    if (!fontExists(key)) {
        return nullptr;
    }

    return m_fonts[key];

}

bool aw::AssetStore::registerFont (const std::string& key, const std::shared_ptr<sf::Font>& font) {

    if (fontExists(key)) {
        return false;
    }

    m_fonts.insert(std::pair<std::string, std::shared_ptr<sf::Font>>(key, font));
    return true;

}

bool aw::AssetStore::registerFont (const std::string& key, sf::Font* font) {

    return registerFont(key, std::shared_ptr<sf::Font>(font));

}

void aw::AssetStore::deleteFont (const std::string& key) {

    if (!fontExists(key)) {
        return;
    }

    m_fonts[key].reset();
    m_fonts.erase(key);

}

std::unordered_map<std::string, std::shared_ptr<sf::Image>> aw::AssetStore::m_images;
std::unordered_map<std::string, std::shared_ptr<sf::Sound>> aw::AssetStore::m_sounds;
std::unordered_map<std::string, std::shared_ptr<sf::Font>> aw::AssetStore::m_fonts;
