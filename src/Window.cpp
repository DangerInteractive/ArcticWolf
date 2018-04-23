#include "../include/Window.hpp"

sf::RenderWindow* aw::Window::getContext () {

    return m_context.get();

}

bool aw::Window::exists () {

    if (m_context) {
        return true;
    }

    return false;

}

bool aw::Window::isOpen () {

    if (Window::exists() && m_context->isOpen()) {
        return true;
    }

    return false;

}

void aw::Window::open () {

    if (Window::exists()) {
        aw::Log::warning("window", "Window cannot be opened because it is already open.");
        return;
    }

    m_context = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(m_width, m_height),
        m_title,
        sf::Style::Close | /*sf::Style::Resize |*/ sf::Style::Titlebar
    );

    if (!m_context) {
        aw::Log::error("window", "Failed to create a window.");
        return;
    }

    aw::Log::verbose("window", "Window opened.");

}

void aw::Window::close () {

    if (!Window::isOpen()) {
        aw::Log::warning("window", "Window cannot be closed because it is not open.");
    }

    aw::Log::verbose("window", "Closing window.");
    m_context->close();
    if (m_context) {
        m_context.reset();
    }

}

void aw::Window::display () {

    if (!Window::exists()) {
        aw::Log::warning("window", "Cannot display window because it is not open.");
        return;
    }

    m_context->display();

}

void aw::Window::draw (const sf::Drawable& drawable, const sf::RenderStates& states) {

    m_context->draw(drawable, states);

}

void aw::Window::clear () {

    if (!Window::exists()) {
        aw::Log::warning("window", "Cannot clear window because it is not open.");
        return;
    }

    m_context->clear();

}

void aw::Window::clear (const sf::Color& color) {

    if (!Window::exists()) {
        aw::Log::warning("window", "Cannot clear window because it is not open.");
    }

    m_context->clear(color);

}

bool aw::Window::pollEvent (sf::Event& windowEvent) {

    return m_context->pollEvent(windowEvent);

}

int aw::Window::getWidth () {

    return m_width;

}

int aw::Window::getHeight () {

    return m_height;

}

void aw::Window::setWidth (int width) {

    std::unique_lock<std::mutex> lock_size(mutex_size);

    m_width = width;
    pushWindowSize();

}

void aw::Window::setHeight (int height) {

    std::unique_lock<std::mutex> lock_size(mutex_size);

    m_height = height;
    pushWindowSize();

}

void aw::Window::setSize (int width, int height) {

    std::unique_lock<std::mutex> lock_size(mutex_size);

    m_width = width;
    m_height = height;
    pushWindowSize();

}

std::string aw::Window::getTitle () {

    return m_title;

}

void aw::Window::setTitle (const std::string& title) {

    std::unique_lock<std::mutex> lock_title(mutex_title);

    m_title = title;
    pushWindowTitle();

}

void aw::Window::pushWindowSize () {

    if (m_context) {
        m_context->setSize(sf::Vector2u(m_width, m_height));
    }

}

void aw::Window::pushWindowTitle () {

    if (m_context) {
        m_context->setTitle(sf::String(m_title));
    }

}

std::unique_ptr<sf::RenderWindow> aw::Window::m_context;

int aw::Window::m_width = 800;
int aw::Window::m_height = 600;
std::mutex aw::Window::mutex_size;

std::string aw::Window::m_title = "";
std::mutex aw::Window::mutex_title;
