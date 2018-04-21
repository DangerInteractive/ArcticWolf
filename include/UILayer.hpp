#ifndef H_CLASS_UILAYER
#define H_CLASS_UILAYER

#include <map>
#include "Layer.hpp"
#include "UIElement.hpp"

namespace aw {
class UILayer : public Layer {

public:

    UILayer () = default;
    ~UILayer () = default;

    UILayer (UILayer&&) = default;
    UILayer& operator = (UILayer&&) = default;

    UILayer (const UILayer&) = default;
    UILayer& operator = (const UILayer&) = default;

protected:

    std::map<int, UIElement> m_elements;

};
}

#endif
