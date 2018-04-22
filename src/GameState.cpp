#include "../include/GameState.hpp"

void aw::GameState::clearWindow () {

    if (m_clearWindow) {
        Window::clear(m_clearColor);
    }

}

aw::Controller& aw::GameState::getController () {

    return m_controller;

}

void aw::GameState::setController (Controller& controller) {

    m_controller = controller;

}

void aw::GameState::clearController () {

    m_controller = Controller();

}
