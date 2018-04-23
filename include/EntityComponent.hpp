#ifndef H_AW_ENTITYCOMPONENT
#define H_AW_ENTITYCOMPONENT

#include "Entity.hpp"
#include "Layer.hpp"
#include "Scene.hpp"

namespace aw {
class EntityComponent {

public:

    EntityComponent () = default;
    explicit EntityComponent (Entity*);
    ~EntityComponent () = default;

    EntityComponent (EntityComponent&&) = default;
    EntityComponent& operator = (EntityComponent&&) = default;

    EntityComponent (const EntityComponent&) = default;
    EntityComponent& operator = (const EntityComponent&) = default;

    Entity* getEntity () const;
    Layer* getLayer () const;
    Scene* getScene () const;

    bool onAttachEntity (Entity*);
    bool onDetachEntity ();

    bool onAttachLayer (Layer*);
    bool onDetachLayer ();

    bool onAttachScene (Scene*);
    bool onDetachScene ();

protected:

    virtual void attachEntityCallback (Entity*) = 0;
    virtual void detachEntityCallback () = 0;

    virtual void attachLayerCallback (Layer*) = 0;
    virtual void detachLayerCallback () = 0;

    virtual void attachSceneCallback (Scene*) = 0;
    virtual void detachSceneCallback () = 0;

    Entity* m_entity {nullptr};

};
}

#endif
