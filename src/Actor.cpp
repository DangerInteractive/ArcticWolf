#include "../include/Actor.hpp"

aw::Layer* aw::Actor::getLayer () const {

    return m_layer;

}

aw::Scene* aw::Actor::getScene () const {

    return m_layer->getScene();

}
