#include "../include/FunctionLogObserver.hpp"

aw::FunctionLogObserver::FunctionLogObserver (const std::vector<Callback>& callbacks)
: LogObserver() {

    setCallbacks(callbacks);

}

aw::FunctionLogObserver::FunctionLogObserver (const Callback& callbacks...)
: LogObserver() {

    addCallback(callbacks);

}

aw::FunctionLogObserver::FunctionLogObserver (const std::vector<Callback>& callbacks, unsigned int allowedLevelFlags)
: LogObserver(allowedLevelFlags) {

    setCallbacks(callbacks);

}

aw::FunctionLogObserver::FunctionLogObserver (const Callback& callback, unsigned int allowedLevelFlags)
: LogObserver(allowedLevelFlags) {

    addCallback(callback);

}

aw::FunctionLogObserver::FunctionLogObserver (const std::vector<Callback>& callbacks, const std::set<std::string>& allowedContexts)
: LogObserver(allowedContexts) {

    setCallbacks(callbacks);

}

aw::FunctionLogObserver::FunctionLogObserver (const Callback& callback, const std::set<std::string>& allowedContexts)
: LogObserver(allowedContexts) {

    addCallback(callback);

}

aw::FunctionLogObserver::FunctionLogObserver (const std::vector<Callback>& callbacks, const std::string& allowedContexts...)
: LogObserver(allowedContexts) {

    setCallbacks(callbacks);

}

aw::FunctionLogObserver::FunctionLogObserver (const Callback& callback, const std::string& allowedContexts...)
: LogObserver(allowedContexts) {

    addCallback(callback);

}

aw::FunctionLogObserver::FunctionLogObserver (const std::vector<Callback>& callbacks, unsigned int allowedLevelFlags, const std::set<std::string>& allowedContexts)
: LogObserver(allowedLevelFlags, allowedContexts) {

    setCallbacks(callbacks);

}

aw::FunctionLogObserver::FunctionLogObserver (const Callback& callback, unsigned int allowedLevelFlags, const std::set<std::string>& allowedContexts)
: LogObserver(allowedLevelFlags, allowedContexts) {

    addCallback(callback);

}

aw::FunctionLogObserver::FunctionLogObserver (const std::vector<Callback>& callbacks, unsigned int allowedLevelFlags, const std::string& allowedContexts...)
: LogObserver(allowedLevelFlags, allowedContexts) {

    setCallbacks(callbacks);

}

aw::FunctionLogObserver::FunctionLogObserver (const Callback& callback, unsigned int allowedLevelFlags, const std::string& allowedContexts...)
: LogObserver(allowedLevelFlags, allowedContexts) {

    addCallback(callback);

}

void aw::FunctionLogObserver::notifyCallback (LogLevel logLevel, const std::string& context, const std::string& message) {

    std::unique_lock<std::mutex> lock(m_mutex);

    for (unsigned int i = 0; i < m_callbacks.size(); ++i) {

        m_callbacks[i](logLevel, context, message);

    }

}

const std::vector<aw::FunctionLogObserver::Callback>& aw::FunctionLogObserver::getCallbacks () const {

    return m_callbacks;

}

void aw::FunctionLogObserver::setCallbacks (const std::vector<Callback>& callbacks) {

    m_callbacks = callbacks;

}

void aw::FunctionLogObserver::addCallback (const Callback& callback...) {

    m_callbacks.push_back(callback);

}

void aw::FunctionLogObserver::clearCallbacks () {

    m_callbacks.clear();

}
