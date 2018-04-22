#include "../include/Component.hpp"

aw::Component::Component (aw::Actor* actor) {

    onAttachActor(actor);

}

aw::Actor* aw::Component::getActor () const {

    return m_actor;

}

aw::Layer* aw::Component::getLayer () const {

    return m_actor->getLayer();

}

aw::Scene* aw::Component::getScene () const {

    return m_actor->getScene();

}

bool aw::Component::onAttachActor (Actor* actor) {

    if (m_actor != nullptr) {
        onDetachActor();
    }

    if (actor != nullptr) {
        attachActorCallback(actor);
        m_actor = actor;
        if (actor->getLayer() != nullptr) {
            onAttachLayer(actor->getLayer());
            if (actor->getScene() != nullptr) {
                onAttachScene(actor->getScene());
            } else {
                onDetachScene();
            }
        } else {
            onDetachLayer();
        }
    } else {
        if (m_actor != nullptr) {
            onDetachActor();
        }
    }

    return true;

}

bool aw::Component::onDetachActor () {

    if (m_actor->getScene() != nullptr) {
        onDetachScene();
    }

    if (m_actor->getLayer() != nullptr) {
        onDetachLayer();
    }

    detachActorCallback();

    m_actor = nullptr;

    return true;

}

bool aw::Component::onAttachLayer (Layer* layer) {

    if (m_actor == nullptr) {
        return false;
    }

    if (m_actor->getLayer() != nullptr) {
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
        if (m_actor->getLayer() != nullptr) {
            onDetachLayer();
        }
    }

    return true;

}

bool aw::Component::onDetachLayer () {

    if (m_actor == nullptr) {
        return false;
    }

    if (m_actor->getScene() != nullptr) {
        onDetachScene();
    }

    detachLayerCallback();

    return true;

}

bool aw::Component::onAttachScene (Scene* scene) {

    if (m_actor == nullptr || m_actor->getScene() == nullptr) {
        return false;
    }

    if (m_actor->getScene() != nullptr) {
        onDetachScene();
    }

    if (scene != nullptr) {
        attachSceneCallback(scene);
    } else {
        if (m_actor->getLayer() != nullptr) {
            onDetachScene();
        }
    }

    return true;

}

bool aw::Component::onDetachScene () {

    if (m_actor == nullptr || m_actor->getLayer() == nullptr) {
        return false;
    }

    detachSceneCallback();

    return true;

}
