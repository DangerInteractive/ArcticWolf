#include "../include/Layer.hpp"

aw::Scene* aw::Layer::getScene () const {

    return m_scene;

}

double aw::Layer::getZIndex () const {

    return m_zIndex;

}

bool aw::Layer::operator == (const Layer& right) const {

    return (getZIndex() == right.getZIndex());

}

bool aw::Layer::operator != (const Layer& right) const {

    return (getZIndex() != right.getZIndex());

}

bool aw::Layer::operator > (const Layer& right) const {

    return (getZIndex() > right.getZIndex());

}

bool aw::Layer::operator >= (const Layer& right) const {

    return (getZIndex() >= right.getZIndex());

}

bool aw::Layer::operator < (const Layer& right) const {

    return (getZIndex() < right.getZIndex());

}

bool aw::Layer::operator <= (const Layer& right) const {

    return (getZIndex() <= right.getZIndex());

}
