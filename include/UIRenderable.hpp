#ifndef H_AW_UIRENDERABLE
#define H_AW_UIRENDERABLE

#include "Renderable.hpp"

namespace aw {
class UIRenderable : public Renderable {

public:

    UIRenderable () = default;
    virtual ~UIRenderable () = default;

    UIRenderable (UIRenderable&&) = default;
    UIRenderable& operator = (UIRenderable&&) = default;

    UIRenderable (const UIRenderable&) = default;
    UIRenderable& operator = (const UIRenderable&) = default;

};
}

#endif
