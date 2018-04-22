#include "../include/UILayer.hpp"

aw::UILayer::UILayer () {

    m_renderCache = generateRenderCache();

}

void aw::UILayer::onNewElement (UIElement* element) {

    m_renderCache.push(element);

}

void aw::UILayer::onRenderCacheInvalidate () {

    auto newCache = generateRenderVector();

    m_renderCache = newCache;

}

aw::PriorityVector<aw::UIElement*, std::greater<aw::UIElement*>> aw::UILayer::generateRenderCache () {

    PriorityVector<UIElement*, std::greater<UIElement*>> cache;

    auto elements = m_root->getAll();

    for (unsigned int i = 0; i < elements.size(); ++i) {
        cache.push(elements[i]);
    }

    return cache;

}
