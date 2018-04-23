#include "../include/Renderable.hpp"

aw::Renderable::Renderable (double zIndex)
: m_zIndex(zIndex) {}

aw::Renderable::Renderable (double zIndex, double parallax)
: m_zIndex(zIndex), m_parallax(parallax) {}

double aw::Renderable::getZIndex () const {

    return m_zIndex;

}

bool aw::Renderable::zIndexDirty () const {

    return m_dirtyZIndex;

}

double aw::Renderable::getParallax () const {

    return m_parallax;

}

void aw::Renderable::setZIndex (double zIndex) {

    m_zIndex = zIndex;
    m_dirtyZIndex = true;

}

void aw::Renderable::resetDirtyZIndex () {

    m_dirtyZIndex = false;

}

void aw::Renderable::setParallax (double parallax) {

    m_parallax = parallax;

}
