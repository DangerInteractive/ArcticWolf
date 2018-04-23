#ifndef H_AW_RENDERABLE
#define H_AW_RENDERABLE

#include <memory>
#include <SFML/Graphics.hpp>

namespace aw { class RenderComponent; }

namespace aw {
class Renderable {

public:

    Renderable () = default;
    explicit Renderable (RenderComponent*);
    explicit Renderable (double);
    Renderable (double, RenderComponent*);
    explicit Renderable (sf::Drawable*);
    Renderable (sf::Drawable*, RenderComponent*);
    Renderable (double, sf::Drawable*);
    Renderable (double, sf::Drawable*, RenderComponent*);
    virtual ~Renderable () = default;

    Renderable (Renderable&&) = default;
    Renderable& operator = (Renderable&&) = default;

    Renderable (const Renderable&) = default;
    Renderable& operator = (const Renderable&) = default;

    virtual void render (sf::RenderTarget*);

    RenderComponent* getOwner ();
    double getZIndex () const;
    virtual sf::Drawable* get ();

    void setOwner (RenderComponent*);
    void setZIndex (double);
    virtual void set (sf::Drawable*);

protected:

    double m_zIndex {0.0};

    std::unique_ptr<sf::Drawable> m_drawable {nullptr};

    RenderComponent* m_owner {nullptr};

};
}

#endif
