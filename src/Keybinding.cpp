#include "../include/Keybinding.hpp"

aw::Keybinding::Keybinding (
    const KeybindingCallback& callback,
    bool action,
    sf::Keyboard::Key key,
    bool alt,
    bool control,
    bool shift
)
: m_callback(callback), m_action(action), m_key(key), m_alt(alt), m_control(control), m_shift(shift) {}

bool aw::Keybinding::check (bool action, sf::Keyboard::Key key, bool alt, bool control, bool shift) const {

    if (
        action == m_action &&
        key == m_key &&
        alt == m_alt &&
        control == m_control &&
        shift == m_shift
    ) {
        return true;
    } else {
        return false;
    }

}

void aw::Keybinding::process (bool action, sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    if (check(action, key, alt, control, shift)) {
        m_callback();
    }

}

const aw::Keybinding::KeybindingCallback& aw::Keybinding::getCallback () const {

    return m_callback;

}

bool aw::Keybinding::getAction () const {

    return m_action;

}

sf::Keyboard::Key aw::Keybinding::getKey () const {

    return m_key;

}

bool aw::Keybinding::getAlt () const {

    return m_alt;

}

bool aw::Keybinding::getControl () const {

    return m_control;

}

bool aw::Keybinding::getShift () const {

    return m_shift;

}

void aw::Keybinding::setCallback (const KeybindingCallback& callback) {

    m_callback = callback;

}

void aw::Keybinding::setAction (bool action) {

    m_action = action;

}

void aw::Keybinding::setKey (sf::Keyboard::Key key) {

    m_key = key;

}

void aw::Keybinding::setAlt (bool alt) {

    m_alt = alt;

}

void aw::Keybinding::setControl (bool control) {

    m_control = control;

}

void aw::Keybinding::setShift (bool shift) {

    m_shift = shift;

}
