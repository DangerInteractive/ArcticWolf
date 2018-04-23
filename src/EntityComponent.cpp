#include "../include/EntityComponent.hpp"

aw::EntityComponent::EntityComponent (aw::Entity* entity) {

    onAttachEntity(entity);

}

aw::Entity* aw::EntityComponent::getEntity () const {

    return m_entity;

}

aw::Layer* aw::EntityComponent::getLayer () const {

    return m_entity->getLayer();

}

aw::Scene* aw::EntityComponent::getScene () const {

    return m_entity->getScene();

}

bool aw::EntityComponent::onAttachEntity (Entity* entity) {

    if (m_entity != nullptr) {
        onDetachEntity();
    }

    if (entity != nullptr) {
        attachEntityCallback(entity);
        m_entity = entity;
        if (entity->getLayer() != nullptr) {
            onAttachLayer(entity->getLayer());
            if (entity->getScene() != nullptr) {
                onAttachScene(entity->getScene());
            } else {
                onDetachScene();
            }
        } else {
            onDetachLayer();
        }
    } else {
        if (m_entity != nullptr) {
            onDetachEntity();
        }
    }

    return true;

}

bool aw::EntityComponent::onDetachEntity () {

    if (m_entity->getScene() != nullptr) {
        onDetachScene();
    }

    if (m_entity->getLayer() != nullptr) {
        onDetachLayer();
    }

    detachEntityCallback();

    m_entity = nullptr;

    return true;

}

bool aw::EntityComponent::onAttachLayer (Layer* layer) {

    if (m_entity == nullptr) {
        return false;
    }

    if (m_entity->getLayer() != nullptr) {
        onDetachLayer();
    }

    if (layer != nullptr) {
        attachLayerCallback(layer);
        if (layer->getScene() != nullptr) {
            onAttachScene(layer->getScene());
        } else {
            onDetachScene();
        }
    } else {
        if (m_entity->getLayer() != nullptr) {
            onDetachLayer();
        }
    }

    return true;

}

bool aw::EntityComponent::onDetachLayer () {

    if (m_entity == nullptr) {
        return false;
    }

    if (m_entity->getScene() != nullptr) {
        onDetachScene();
    }

    detachLayerCallback();

    return true;

}

bool aw::EntityComponent::onAttachScene (Scene* scene) {

    if (m_entity == nullptr || m_entity->getScene() == nullptr) {
        return false;
    }

    if (m_entity->getScene() != nullptr) {
        onDetachScene();
    }

    if (scene != nullptr) {
        attachSceneCallback(scene);
    } else {
        if (m_entity->getLayer() != nullptr) {
            onDetachScene();
        }
    }

    return true;

}

bool aw::EntityComponent::onDetachScene () {

    if (m_entity == nullptr || m_entity->getLayer() == nullptr) {
        return false;
    }

    detachSceneCallback();

    return true;

}
