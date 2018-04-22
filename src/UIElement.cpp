#include "../include/UIElement.hpp"

const std::vector<std::unique_ptr<aw::UIElement>>& aw::UIElement::getChildrenReference () const {

    return m_children;

}

std::vector<aw::UIElement*> aw::UIElement::getChildren () {

    std::vector<UIElement*> children;

    for (unsigned int i = 0; i < m_children.size(); ++i) {
        auto childsChildren = m_children[i]->getChildren();
        children.insert(children.end(), childsChildren.begin(), childsChildren.end());
    }

    return children;

}

std::vector<aw::UIElement*> aw::UIElement::getAll () {

    auto children = getChildren();

    children.push_back(this);

    return children;

}

aw::UIElement* aw::UIElement::getParent () {

    return m_parent;

}

aw::UILayer* aw::UIElement::getLayer () {

    return m_layer;

}

double aw::UIElement::getZIndex () const {

    return m_zIndex;

}

double aw::UIElement::getOffsetX () const {

    return m_offsetX;

}

aw::UIElement::SizeUnit aw::UIElement::getOffsetXUnit () const {

    return m_offsetXUnit;

}

double aw::UIElement::getOffsetY () const {

    return m_offsetY;

}

aw::UIElement::SizeUnit aw::UIElement::getOffsetYUnit () const {

    return m_offsetYUnit;

}

double aw::UIElement::getMarginTop () const {

    return m_marginTop;

}

aw::UIElement::SizeUnit aw::UIElement::getMarginTopUnit () const {

    return m_marginTopUnit;

}

double aw::UIElement::getMarginRight () const {

    return m_marginRight;

}

aw::UIElement::SizeUnit aw::UIElement::getMarginRightUnit () const {

    return m_marginRightUnit;

}

double aw::UIElement::getMarginBottom () const {

    return m_marginBottom;

}

aw::UIElement::SizeUnit aw::UIElement::getMarginBottomUnit () const {

    return m_marginBottomUnit;

}

double aw::UIElement::getMarginLeft () const {

    return m_marginLeft;

}

aw::UIElement::SizeUnit aw::UIElement::getMarginLeftUnit () const {

    return m_marginLeftUnit;

}

double aw::UIElement::getBorderWidthTop () const {

    return m_borderWidthTop;

}

aw::UIElement::SizeUnit aw::UIElement::getBorderWidthTopUnit () const {

    return m_borderWidthTopUnit;

}

double aw::UIElement::getBorderWidthRight () const {

    return m_borderWidthRight;

}

aw::UIElement::SizeUnit aw::UIElement::getBorderWidthRightUnit () const {

    return m_borderWidthRightUnit;

}

double aw::UIElement::getBorderWidthBottom () const {

    return m_borderWidthBottom;

}

aw::UIElement::SizeUnit aw::UIElement::getBorderWidthBottomUnit () const {

    return m_borderWidthBottomUnit;

}

double aw::UIElement::getBorderWidthLeft () const {

    return m_borderWidthLeft;

}

aw::UIElement::SizeUnit aw::UIElement::getBorderWidthLeftUnit () const {

    return m_borderWidthLeftUnit;

}

double aw::UIElement::getPaddingTop () const {

    return m_paddingTop;

}

aw::UIElement::SizeUnit aw::UIElement::getPaddingTopUnit () const {

    return m_paddingTopUnit;

}

double aw::UIElement::getPaddingRight () const {

    return m_paddingRight;

}

aw::UIElement::SizeUnit aw::UIElement::getPaddingRightUnit () const {

    return m_paddingRightUnit;

}

double aw::UIElement::getPaddingBottom () const {

    return m_paddingBottom;

}

aw::UIElement::SizeUnit aw::UIElement::getPaddingBottomUnit () const {

    return m_paddingBottomUnit;

}

double aw::UIElement::getPaddingLeft () const {

    return m_paddingLeft;

}

aw::UIElement::SizeUnit aw::UIElement::getPaddingLeftUnit () const {

    return m_paddingLeftUnit;

}

sf::Color aw::UIElement::getBorderColorTop () const {

    return m_borderColorTop;

}

sf::Color aw::UIElement::getBorderColorRight () const {

    return m_borderColorRight;

}

sf::Color aw::UIElement::getBorderColorBottom () const {

    return m_borderColorBottom;

}

sf::Color aw::UIElement::getBorderColorLeft () const {

    return m_borderColorLeft;

}

sf::Color aw::UIElement::getBackgroundColor () const {

    return m_backgroundColor;

}

std::shared_ptr<sf::Image> aw::UIElement::getBackgroundImage () const {

    return m_backgroundImage;

}

double aw::UIElement::getBackgroundImageOffsetX () const {

    return m_backgroundImageOffsetX;

}

aw::UIElement::SizeUnit aw::UIElement::getBackgroundImageOffsetXUnit () const {

    return m_backgroundImageOffsetXUnit;

}

double aw::UIElement::getBackgroundImageOffsetY () const {

    return m_backgroundImageOffsetY;

}

aw::UIElement::SizeUnit aw::UIElement::getBackgroundImageOffsetYUnit () const {

    return m_backgroundImageOffsetYUnit;

}

double aw::UIElement::getBackgroundImageSizeX () const {

    return m_backgroundImageSizeX;

}

aw::UIElement::SizeUnit aw::UIElement::getBackgroundImageSizeXUnit () const {

    return m_backgroundImageSizeXUnit;

}

double aw::UIElement::getBackgroundImageSizeY () const {

    return m_backgroundImageSizeY;

}

aw::UIElement::SizeUnit aw::UIElement::getBackgroundImageSizeYUnit () const {

    return m_backgroundImageSizeYUnit;

}

void aw::UIElement::onDirtyZIndex (UIElement* element) {

    if (m_parent != nullptr) {
        m_parent->onDirtyZIndex(element);
    } else {
        if (m_layer != nullptr) {
            m_layer->onRenderCacheInvalidate();
        }
    }

}

bool aw::UIElement::operator < (const UIElement& right) const {

    return (getZIndex() < right.getZIndex());

}

bool aw::UIElement::operator <= (const UIElement& right) const {

    return (getZIndex() <= right.getZIndex());

}

bool aw::UIElement::operator > (const UIElement& right) const {

    return (getZIndex() > right.getZIndex());

}

bool aw::UIElement::operator >= (const UIElement& right) const {

    return (getZIndex() >= right.getZIndex());

}

bool aw::UIElement::operator == (const UIElement& right) const {

    return (getZIndex() == right.getZIndex());

}

bool aw::UIElement::operator != (const UIElement& right) const {

    return (getZIndex() != right.getZIndex());

}

void aw::UIElement::dirtyZIndexCallback () {

    return;

}
