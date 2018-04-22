#include "../include/LoopKeybinding.hpp"

aw::LoopKeybinding::LoopKeybinding (
    const LoopKeybindingCallback& callback,
    sf::Keyboard::Key key
)
: m_callback(callback), m_keys(std::vector<sf::Keyboard::Key>(1, key)) {}

aw::LoopKeybinding::LoopKeybinding (
    const LoopKeybindingCallback& callback,
    const std::vector<sf::Keyboard::Key>& keys
) :
  m_callback(callback),
  m_keys(keys)
{}

bool aw::LoopKeybinding::check (const std::vector<sf::Keyboard::Key>& keys) {

    for (int i = 0; i < m_keys.size(); ++i) {
        bool found = false;
        for (int j = 0; j < keys.size(); ++j) {
            if (m_keys[i] == keys[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        } else {
            found = false;
        }
    }

    return true;

}

void aw::LoopKeybinding::process (const std::vector<sf::Keyboard::Key>& keys) {

    if (check(keys)) {
        m_callback();
    }

}

const aw::LoopKeybinding::LoopKeybindingCallback& aw::LoopKeybinding::getCallback () const {

    return m_callback;

}

std::vector<sf::Keyboard::Key> aw::LoopKeybinding::getKeys () const {

    return m_keys;

}

void aw::LoopKeybinding::setCallback (const LoopKeybindingCallback& callback) {

    m_callback = callback;

}

void aw::LoopKeybinding::setKeys (const std::vector<sf::Keyboard::Key>& keys) {

    m_keys = keys;

}
