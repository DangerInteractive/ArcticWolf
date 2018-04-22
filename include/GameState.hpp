#ifndef H_AW_GAMESTATE
#define H_AW_GAMESTATE

#include "Controller.hpp"
#include "Window.hpp"
namespace aw { class GameStateManager; }

namespace aw {
class GameState {

public:

    // GameState stacking transparency flags
    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    // constructor and destructor
    GameState () = default;
    virtual ~GameState () = default;

    // move operations (implement these in derived classes)
    GameState (GameState&&) = default;
    GameState& operator = (GameState&&) = default;

    // copy operations (implement these in derived classes)
    GameState (const GameState&) = default;
    GameState& operator = (const GameState&) = default;

    // state management event callbacks
    virtual void onActivate () = 0;
    virtual void onDeactivate () = 0;
    virtual void onPush () = 0;
    virtual void onPop () = 0;
    virtual void onAscend () = 0;
    virtual void onDescend () = 0;

    // game loop callbacks
    void clearWindow ();
    virtual void render (double) = 0;
    virtual void update () = 0;

    // input handling
    Controller& getController ();
    void setController (Controller&);
    void clearController ();

protected:

    Controller m_controller;
    bool m_clearWindow {false};
    sf::Color m_clearColor {0, 0, 0, 255};

};
}

#endif
