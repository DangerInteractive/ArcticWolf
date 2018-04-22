#include "../include/Renderable.hpp"
#include "../include/RenderComponent.hpp"

aw::Renderable::Renderable (RenderComponent* owner)
: m_owner(owner) {}

aw::Renderable::Renderable (double zIndex)
: m_zIndex(zIndex) {}

aw::Renderable::Renderable (double zIndex, RenderComponent* owner)
: m_zIndex(zIndex), m_owner(owner) {}

aw::Renderable::Renderable (sf::Drawable* drawable) {

    set(drawable);

}

aw::Renderable::Renderable (sf::Drawable* drawable, RenderComponent* owner)
: m_owner(owner) {

    set(drawable);

}

aw::Renderable::Renderable (double zIndex, sf::Drawable* drawable)
: m_zIndex(zIndex) {

    set(drawable);

}

aw::Renderable::Renderable (double zIndex, sf::Drawable* drawable, RenderComponent* owner)
: m_zIndex(zIndex), m_owner(owner) {

    set(drawable);

}

aw::RenderComponent* aw::Renderable::getOwner () {

    return m_owner;

}

double aw::Renderable::getZIndex () const {

    return m_zIndex;

}

sf::Drawable* aw::Renderable::get () {

    return m_drawable.get();

}

void aw::Renderable::setOwner (RenderComponent* owner) {

    m_owner = owner;

}

void aw::Renderable::setZIndex (double zIndex) {

    m_zIndex = zIndex;

    if (m_owner != nullptr) {
        m_owner->onDirtyZIndex(this);
    }

}

void aw::Renderable::set (sf::Drawable* drawable) {

    m_drawable.reset();
    m_drawable = std::unique_ptr<sf::Drawable>(drawable);

}
