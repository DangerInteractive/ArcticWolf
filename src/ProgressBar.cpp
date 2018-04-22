#include "../include/ProgressBar.hpp"

aw::ProgressBar::ProgressBar (
    float width,
    float height,
    float padding,
    float positionX,
    float positionY,
    float originX,
    float originY,
    const sf::Color& backgroundColor,
    const sf::Color& foregroundColor
) {

    setWidth(width);
    setHeight(height);
    setPadding(padding);
    setPositionX(positionX);
    setPositionY(positionY);
    setOriginX(originX);
    setOriginY(originY);
    setBackgroundColor(backgroundColor);
    setForegroundColor(foregroundColor);

}

aw::ProgressBar::~ProgressBar () {}

void aw::ProgressBar::render () {

    Window::draw(m_backgroundRect);
    Window::draw(m_foregroundRect);

}

void aw::ProgressBar::setPosition (float x, float y) {

    setPositionX(x);
    setPositionY(y);

}

void aw::ProgressBar::setPositionX (float x) {

    m_positionX = x;

    updatePositionX();

}

void aw::ProgressBar::setPositionY (float y) {

    m_positionY = y;

    updatePositionY();

}

void aw::ProgressBar::setOrigin (float x, float y) {

    setOriginX(x);
    setOriginY(y);

}

void aw::ProgressBar::setOriginX (float x) {

    m_originX = x;

    updateOriginX();

}

void aw::ProgressBar::setOriginY (float y) {

    m_originY = y;

    updateOriginY();

}

void aw::ProgressBar::setOriginToCenter () {

    setOriginX(m_width * 0.5);
    setOriginY(m_height * 0.5);

}

void aw::ProgressBar::setOriginToTopLeft () {

    setOriginX(0);
    setOriginY(0);

}

double aw::ProgressBar::getFill () const {

    return m_fill;

}

float aw::ProgressBar::getWidth () const {

    return m_width;

}

float aw::ProgressBar::getHeight () const {

    return m_height;

}

float aw::ProgressBar::getPadding () const {

    return m_padding;

}

sf::Color aw::ProgressBar::getBackgroundColor () const {

    return m_backgroundColor;

}

sf::Color aw::ProgressBar::getForegroundColor () const {

    return m_foregroundColor;

}

void aw::ProgressBar::setFill (double fill) {

    if (fill < 0) {
        fill = 0;
    } else if (fill > 1.0) {
        fill = 1.0;
    }

    m_fill = fill;

    updateFill();

}

double aw::ProgressBar::incrementFill (double fill) {

    fill += m_fill;
    setFill(fill);

    return m_fill;

}

double aw::ProgressBar::decrementFill (double fill) {

    fill = m_fill - fill;
    setFill(fill);

    return m_fill;

}

void aw::ProgressBar::setWidth (float width) {

    if (width < 0.0) {
        width = 0.0;
    }

    m_width = width;

    updateWidth();

}

void aw::ProgressBar::setHeight (float height) {

    if (height < 0.0) {
        height = 0.0;
    }

    m_height = height;

    updateHeight();

}

void aw::ProgressBar::setPadding (float padding) {

    m_padding = padding;

    updatePadding();

}

void aw::ProgressBar::setBackgroundColor (const sf::Color& color) {

    m_backgroundColor = color;

    updateBackgroundColor();

}

void aw::ProgressBar::setForegroundColor (const sf::Color& color) {

    m_foregroundColor = color;

    updateForegroundColor();

}

void aw::ProgressBar::updatePositionX () {

    m_backgroundRect.setPosition(m_positionX - m_originX, m_backgroundRect.getPosition().y);
    m_foregroundRect.setPosition(m_positionX + m_padding - m_originX, m_foregroundRect.getPosition().y);

}

void aw::ProgressBar::updatePositionY () {

    m_backgroundRect.setPosition(m_backgroundRect.getPosition().x, m_positionY - m_originY);
    m_foregroundRect.setPosition(m_foregroundRect.getPosition().x, m_positionY + m_padding - m_originY);

}

void aw::ProgressBar::updateOriginX () {

    updatePositionX();

}

void aw::ProgressBar::updateOriginY () {

    updatePositionY();

}

void aw::ProgressBar::updateWidth () {

    m_backgroundRect.setSize(
        sf::Vector2f(
            m_width,
            m_backgroundRect.getSize().y
        )
    );
    m_foregroundRect.setSize(
        sf::Vector2f(
            (m_width - (m_padding * 2)) * m_fill,
            m_foregroundRect.getSize().y
        )
    );

}

void aw::ProgressBar::updateHeight () {

    m_backgroundRect.setSize(
        sf::Vector2f(
            m_backgroundRect.getSize().x,
            m_height
        )
    );
    m_foregroundRect.setSize(
        sf::Vector2f(
            m_foregroundRect.getSize().x,
            m_height - (m_padding * 2)
        )
    );

}

void aw::ProgressBar::updateFill () {

    updateWidth();

}

void aw::ProgressBar::updatePadding () {

    updateWidth();
    updateHeight();
    updateOriginX();
    updateOriginY();
    updatePositionX();
    updatePositionY();

}

void aw::ProgressBar::updateBackgroundColor () {

    m_backgroundRect.setFillColor(m_backgroundColor);

}

void aw::ProgressBar::updateForegroundColor () {

    m_foregroundRect.setFillColor(m_foregroundColor);

}
