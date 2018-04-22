#ifndef H_AW_UILAYER
#define H_AW_UILAYER

#include <memory>
#include "Layer.hpp"
#include "PriorityVector.hpp"
#include "PointerGreater.hpp"
#include "UIElement.hpp"

namespace aw {
class UILayer : public Layer {

public:

    typedef PriorityVector<UIElement*, PointerGreater<UIElement*>> UIElementPriorityVector;

    UILayer ();
    ~UILayer () = default;

    UILayer (UILayer&&) = default;
    UILayer& operator = (UILayer&&) = default;

    UILayer (const UILayer&) = default;
    UILayer& operator = (const UILayer&) = default;

    const UIElementPriorityVector& getRenderVector () const;

    void onNewElement (UIElement*);
    void onRenderCacheInvalidate ();

protected:

    UIElementPriorityVector generateRenderCache () const;

    std::unique_ptr<UIElement> m_root;

    UIElementPriorityVector m_renderCache;

};
}

#endif
