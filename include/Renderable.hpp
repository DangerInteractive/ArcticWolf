#ifndef H_AW_RENDERABLE
#define H_AW_RENDERABLE

#include <memory>
#include <SFML/Graphics.hpp>

namespace aw {
class Renderable {

public:

    Renderable () = default;
    explicit Renderable (double);
    explicit Renderable (double, double);
    ~Renderable () = default;

    Renderable (Renderable&&) = default;
    Renderable& operator = (Renderable&&) = default;

    Renderable (const Renderable&) = default;
    Renderable& operator = (const Renderable&) = default;

    double getZIndex () const;
    bool zIndexDirty () const;

    double getParallax () const;

    void setZIndex (double);
    void resetDirtyZIndex ();

    void setParallax (double);

protected:

    double m_zIndex {0.0};
    bool m_dirtyZIndex {false};

    double m_parallax {1.0};

};
}

#endif
