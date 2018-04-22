#include "../include/Controller.hpp"

void aw::Controller::loopCheck () {

    if (m_mouseIsDown) {
        onLoopMouseButton(m_lastButtons, m_lastMouseX, m_lastMouseY);
    }

    std::vector<sf::Keyboard::Key> down;
    for (int i = 0; i < m_keysToLoop.size(); ++i) {
        if (sf::Keyboard::isKeyPressed(m_keysToLoop[i])) {
            down.push_back(m_keysToLoop[i]);
        }
    }

    if (down.size() > 0) {
        onLoopKey(down);
    }

}

void aw::Controller::onKeyPress (sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    for (int i = 0; i < m_keybindings.size(); ++i) {
        m_keybindings[i].process(true, key, alt, control, shift);
    }

}

void aw::Controller::onKeyRelease (sf::Keyboard::Key key, bool alt, bool control, bool shift) {

    for (int i = 0; i < m_keybindings.size(); ++i) {
        m_keybindings[i].process(false, key, alt, control, shift);
    }

}

void aw::Controller::onLoopKey (const std::vector<sf::Keyboard::Key>& keys) {

    for (int i = 0; i < m_loopKeybindings.size(); ++i) {
        m_loopKeybindings[i].process(keys);
    }

}

void aw::Controller::onText (sf::Uint32 character) {

    for (int i = 0; i < m_textCallbacks.size(); ++i) {
        m_textCallbacks[i](character);
    }

}

void aw::Controller::onCursor (double xPos, double yPos) {

    m_lastMouseX = xPos;
    m_lastMouseY = yPos;
    for (int i = 0; i < m_cursorCallbacks.size(); ++i) {
        m_cursorCallbacks[i](xPos, yPos);
    }

}

void aw::Controller::onCursorIn () {

    for (int i = 0; i < m_cursorInCallbacks.size(); ++i) {
        m_cursorInCallbacks[i]();
    }

}

void aw::Controller::onCursorOut () {

    for (int i = 0; i < m_cursorOutCallbacks.size(); ++i) {
        m_cursorOutCallbacks[i]();
    }

}

void aw::Controller::onFocus () {

    for (int i = 0; i < m_focusCallbacks.size(); ++i) {
        m_focusCallbacks[i]();
    }

}

void aw::Controller::onUnfocus () {

    for (int i = 0; i < m_unfocusCallbacks.size(); ++i) {
        m_unfocusCallbacks[i]();
    }

}

void aw::Controller::onMouseButtonPress (int buttons, int x, int y) {

    m_lastButtons = buttons;
    m_lastMouseX = x;
    m_lastMouseY = y;
    m_mouseIsDown = true;
    for (int i = 0; i < m_mouseButtonPressCallbacks.size(); ++i) {
        m_mouseButtonPressCallbacks[i](buttons, x, y);
    }

}

void aw::Controller::onMouseButtonRelease (int buttons, int x, int y) {

    m_mouseIsDown = false;
    for (int i = 0; i < m_mouseButtonReleaseCallbacks.size(); ++i) {
        m_mouseButtonReleaseCallbacks[i](buttons, x, y);
    }

}

void aw::Controller::onLoopMouseButton (int buttons, int x, int y) {

    for (int i = 0; i < m_loopMouseButtonCallbacks.size(); ++i) {
        m_loopMouseButtonCallbacks[i](buttons, x, y);
    }

}

void aw::Controller::onScroll (double offset) {

    for (int i = 0; i < m_scrollCallbacks.size(); ++i) {
        m_scrollCallbacks[i](offset);
    }

}

void aw::Controller::onResize (int width, int height) {

    for (int i = 0; i < m_resizeCallbacks.size(); ++i) {
        m_resizeCallbacks[i](width, height);
    }

}

std::vector<aw::Keybinding> aw::Controller::getKeybindings () const {

    return m_keybindings;

}

std::vector<aw::LoopKeybinding> aw::Controller::getLoopKeybindings () const {

    return m_loopKeybindings;

}

void aw::Controller::setKeybindings (const std::vector<Keybinding>& keybindings) {

    m_keybindings = keybindings;

}

void aw::Controller::addKeybinding (const Keybinding& keybinding) {

    m_keybindings.push_back(std::move(keybinding));

}

void aw::Controller::clearKeybindings () {

    m_keybindings = std::vector<Keybinding>();

}

void aw::Controller::setLoopKeybindings (const std::vector<LoopKeybinding>& loopKeybindings) {

    clearLoopKeybindings();

    for (int i = 0; i < loopKeybindings.size(); ++i) {
        addLoopKeybinding(loopKeybindings[i]);
    }

}

void aw::Controller::addLoopKeybinding (const LoopKeybinding& loopKeybinding) {

    for (int i = 0; i < loopKeybinding.getKeys().size(); ++i) {
        bool insert = true;
        for (int j = 0; j < m_keysToLoop.size(); ++j) {
            if (loopKeybinding.getKeys()[i] == m_keysToLoop[j]) {
                insert = false;
                break;
            }
        }
        if (insert) {
            m_keysToLoop.push_back(loopKeybinding.getKeys()[i]);
        } else {
            insert = true;
        }
    }

    m_loopKeybindings.push_back(loopKeybinding);

}

void aw::Controller::clearLoopKeybindings () {

    m_loopKeybindings = std::vector<LoopKeybinding>();
    m_keysToLoop = std::vector<sf::Keyboard::Key>();

}

void aw::Controller::addTextCallback (const TextCallback& textCallback) {

    m_textCallbacks.push_back(textCallback);

}

void aw::Controller::clearTextCallbacks () {

    m_textCallbacks = std::vector<TextCallback>();

}

void aw::Controller::addCursorCallback (const CursorCallback& cursorCallback) {

    m_cursorCallbacks.push_back(cursorCallback);

}

void aw::Controller::clearCursorCallbacks () {

    m_cursorCallbacks = std::vector<CursorCallback>();

}

void aw::Controller::addCursorInCallback (const CursorInCallback& cursorInCallback) {

    m_cursorInCallbacks.push_back(cursorInCallback);

}

void aw::Controller::clearCursorInCallbacks () {

    m_cursorInCallbacks = std::vector<CursorInCallback>();

}

void aw::Controller::addCursorOutCallback (const CursorOutCallback& cursorOutCallback) {

    m_cursorOutCallbacks.push_back(cursorOutCallback);

}

void aw::Controller::clearCursorOutCallbacks () {

    m_cursorOutCallbacks = std::vector<CursorOutCallback>();

}

void aw::Controller::addFocusCallback (const FocusCallback& focusCallback) {

    m_focusCallbacks.push_back(focusCallback);

}

void aw::Controller::clearFocusCallbacks () {

    m_focusCallbacks = std::vector<FocusCallback>();

}

void aw::Controller::addUnfocusCallback (const UnfocusCallback& unfocusCallback) {

    m_unfocusCallbacks.push_back(unfocusCallback);

}

void aw::Controller::clearUnfocusCallbacks () {

    m_unfocusCallbacks = std::vector<UnfocusCallback>();

}

void aw::Controller::addMouseButtonPressCallback (const MouseButtonPressCallback& mouseButtonPressCallback) {

    m_mouseButtonPressCallbacks.push_back(mouseButtonPressCallback);

}

void aw::Controller::clearMouseButtonPressCallbacks () {

    m_mouseButtonPressCallbacks = std::vector<MouseButtonPressCallback>();

}

void aw::Controller::addMouseButtonReleaseCallback (const MouseButtonReleaseCallback& mouseButtonReleaseCallback) {

    m_mouseButtonReleaseCallbacks.push_back(mouseButtonReleaseCallback);

}

void aw::Controller::clearMouseButtonReleaseCallbacks () {

    m_mouseButtonReleaseCallbacks = std::vector<MouseButtonReleaseCallback>();

}

void aw::Controller::addLoopMouseButtonCallback (const LoopMouseButtonCallback& loopMouseButtonCallback) {

    m_loopMouseButtonCallbacks.push_back(loopMouseButtonCallback);

}

void aw::Controller::clearLoopMouseButtonCallbacks () {

    m_loopMouseButtonCallbacks = std::vector<LoopMouseButtonCallback>();

}

void aw::Controller::addScrollCallback (const ScrollCallback& scrollCallback) {

    m_scrollCallbacks.push_back(scrollCallback);

}

void aw::Controller::clearScrollCallbacks () {

    m_scrollCallbacks = std::vector<ScrollCallback>();

}

void aw::Controller::addResizeCallback (const ResizeCallback& resizeCallback) {

    m_resizeCallbacks.push_back(resizeCallback);

}

void aw::Controller::clearResizeCallbacks () {

    m_resizeCallbacks = std::vector<ResizeCallback>();

}
