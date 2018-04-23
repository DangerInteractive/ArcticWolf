#include "../include/Entity.hpp"

aw::Layer* aw::Entity::getLayer () const {

    return m_layer;

}

aw::Scene* aw::Entity::getScene () const {

    return m_layer->getScene();

}
