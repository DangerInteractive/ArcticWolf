#ifndef H_CLASS_UIDRAWABLE
#define H_CLASS_UIDRAWABLE

#include "UIElement.hpp"

namespace aw {
class UIDrawable : public UIElement {

public:

    UIDrawable () = default;
    ~UIDrawable () = default;

    UIDrawable (UIDrawable&&) = default;
    UIDrawable& operator = (UIDrawable&&) = default;

    UIDrawable (const UIDrawable&) = default;
    UIDrawable& operator = (const UIDrawable&) = default;

protected:

    // TODO: either prevent access to m_elements, or rework this polymorphism idea

};
}

#endif
