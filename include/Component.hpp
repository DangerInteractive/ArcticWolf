#ifndef H_AW_COMPONENT
#define H_AW_COMPONENT

#include "Actor.hpp"
#include "Layer.hpp"
#include "Scene.hpp"

namespace aw {
class Component {

public:

    Component () = default;
    explicit Component (Actor*);
    ~Component () = default;

    Component (Component&&) = default;
    Component& operator = (Component&&) = default;

    Component (const Component&) = default;
    Component& operator = (const Component&) = default;

    Actor* getActor () const;
    Layer* getLayer () const;
    Scene* getScene () const;

    bool onAttachActor (Actor*);
    bool onDetachActor ();

    bool onAttachLayer (Layer*);
    bool onDetachLayer ();

    bool onAttachScene (Scene*);
    bool onDetachScene ();

protected:

    virtual void attachActorCallback (Actor*) = 0;
    virtual void detachActorCallback () = 0;

    virtual void attachLayerCallback (Layer*) = 0;
    virtual void detachLayerCallback () = 0;

    virtual void attachSceneCallback (Scene*) = 0;
    virtual void detachSceneCallback () = 0;

    Actor* m_actor {nullptr};

};
}

#endif
