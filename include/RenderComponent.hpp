#ifndef H_AW_RENDERCOMPONENT
#define H_AW_RENDERCOMPONENT

#include "EntityComponent.hpp"
#include "PriorityVector.hpp"
#include "PointerGreater.hpp"
#include "Renderable.hpp"

namespace aw {
class RenderComponent : public EntityComponent {

public:

    typedef PriorityVector<std::unique_ptr<Renderable>, PointerGreater<std::unique_ptr<Renderable>>> RenderablePriorityVector;

    RenderComponent () = default;
    virtual ~RenderComponent () = 0;

    RenderComponent (RenderComponent&&) = default;
    RenderComponent& operator = (RenderComponent&&) = default;

    RenderComponent (const RenderComponent&) = default;
    RenderComponent& operator = (const RenderComponent&) = default;

    void onDirtyZIndex (Renderable*);

    virtual const RenderablePriorityVector& getRenderables ();

protected:

    virtual void dirtyZIndexCallback (Renderable*) {};

    RenderablePriorityVector m_renderables;

};
}

#endif
