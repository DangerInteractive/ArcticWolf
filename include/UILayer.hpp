#ifndef H_AW_UILAYER
#define H_AW_UILAYER

#include <memory>
#include "Layer.hpp"
#include "PriorityVector.hpp"
#include "UIElement.hpp"

namespace aw {
class UILayer : public Layer {

public:

    UILayer ();
    ~UILayer () = default;

    UILayer (UILayer&&) = default;
    UILayer& operator = (UILayer&&) = default;

    UILayer (const UILayer&) = default;
    UILayer& operator = (const UILayer&) = default;

    const std::vector<UIElement*> getRenderVector ();

    void onNewElement (UIElement*);
    void onRenderCacheInvalidate ();

protected:

    PriorityVector<UIElement*, std::greater<UIElement*>> generateRenderCache ();

    std::unique_ptr<UIElement> m_root;

    PriorityVector<UIElement*, std::greater<UIElement*>> m_renderCache;

};
}

#endif
