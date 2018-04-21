#ifndef H_CLASS_UIELEMENT
#define H_CLASS_UIELEMENT

#include <map>

namespace aw {
class UIElement {

public:

    UIElement () = default;
    ~UIElement () = default;

    UIElement (UIElement&&) = default;
    UIElement& operator = (UIElement&&) = default;

    UIElement (const UIElement&) = default;
    UIElement& operator = (const UIElement&) = default;

protected:

    std::map<int, UIElement> m_elements;

};
}

#endif
