#include "../include/Scene.hpp"

aw::Scene::Scene ()
: m_renderCache(generateRenderCache()) {}

aw::Scene::LayerPriorityVector aw::Scene::generateRenderCache () const {

    LayerPriorityVector cache;

    for (unsigned int i = 0; i < m_layers.size(); ++i) {
        cache.push(m_layers[i].get());
    }

    return cache;

}
