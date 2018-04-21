#include "../include/LogObserver.hpp"

aw::LogObserver::LogObserver (unsigned int allowedLevelFlags)
: m_allowedLevelFlags(allowedLevelFlags) {}

aw::LogObserver::LogObserver (const std::set<std::string>& allowedContexts)
: m_allowedContexts(allowedContexts), m_allContextsAllowed(false) {}

aw::LogObserver::LogObserver (const std::string& allowedContexts...)
: m_allContextsAllowed(false) {

    m_allowedContexts.insert(allowedContexts);

}

aw::LogObserver::LogObserver (unsigned int allowedLevelFlags, const std::set<std::string>& allowedContexts)
: m_allowedLevelFlags(allowedLevelFlags), m_allowedContexts(allowedContexts), m_allContextsAllowed(false) {}

aw::LogObserver::LogObserver (unsigned int allowedLevelFlags, const std::string& allowedContexts...)
: m_allowedLevelFlags(allowedLevelFlags), m_allContextsAllowed(false) {

    m_allowedContexts.insert(allowedContexts);

}

void aw::LogObserver::notify (aw::LogLevel logLevel, const std::string& context, const std::string& message) {

    switch (logLevel) {

        case aw::LogLevel::UNDEFINED:
            if (!undefinedAllowed()) {
                return;
            }
            break;

        case aw::LogLevel::VERBOSE:
            if (!verboseAllowed()) {
                return;
            }
            break;

        case aw::LogLevel::NOTICE:
            if (!noticeAllowed()) {
                return;
            }
            break;

        case aw::LogLevel::WARNING:
            if (!warningAllowed()) {
                return;
            }
            break;

        case aw::LogLevel::ERROR:
            if (!errorAllowed()) {
                return;
            }
            break;

        default:
            return;

    }

    if (m_allContextsAllowed || contextAllowed(context)) {

        notifyCallback(logLevel, context, message);

    }

}

bool aw::LogObserver::undefinedAllowed () const {

    return m_allowedLevelFlags & ALLOW_UNDEFINED;

}

void aw::LogObserver::allowUndefined () {

    m_allowedLevelFlags |= ALLOW_UNDEFINED;

}

void aw::LogObserver::blockUndefined () {

    m_allowedLevelFlags &= ~ALLOW_UNDEFINED;

}

bool aw::LogObserver::verboseAllowed () const {

    return m_allowedLevelFlags & ALLOW_VERBOSE;

}

void aw::LogObserver::allowVerbose () {

    m_allowedLevelFlags |= ALLOW_VERBOSE;

}

void aw::LogObserver::blockVerbose () {

    m_allowedLevelFlags &= ~ALLOW_VERBOSE;

}

bool aw::LogObserver::noticeAllowed () const {

    return m_allowedLevelFlags & ALLOW_NOTICE;

}

void aw::LogObserver::allowNotice () {

    m_allowedLevelFlags |= ALLOW_NOTICE;

}

void aw::LogObserver::blockNotice () {

    m_allowedLevelFlags &= ~ALLOW_NOTICE;

}

bool aw::LogObserver::warningAllowed () const {

    return m_allowedLevelFlags & ALLOW_WARNING;

}

void aw::LogObserver::allowWarning () {

    m_allowedLevelFlags |= ALLOW_WARNING;

}

void aw::LogObserver::blockWarning () {

    m_allowedLevelFlags &= ~ALLOW_WARNING;

}

bool aw::LogObserver::errorAllowed () const {

    return m_allowedLevelFlags & ALLOW_ERROR;

}

void aw::LogObserver::allowError () {

    m_allowedLevelFlags |= ALLOW_ERROR;

}

void aw::LogObserver::blockError () {

    m_allowedLevelFlags &= ~ALLOW_ERROR;

}

bool aw::LogObserver::contextAllowed (const std::string& contexts...) const {

    return m_allowedContexts.find(contexts) != m_allowedContexts.end();

}

void aw::LogObserver::allowContext(const std::string& contexts...) {

    m_allowedContexts.insert(contexts);

}

void aw::LogObserver::blockContext(const std::string& contexts...) {

    m_allowedContexts.erase(contexts);

}

bool aw::LogObserver::allContextAllowed () const {

    return m_allContextsAllowed;

}

void aw::LogObserver::allowAllContext () {

    m_allContextsAllowed = true;

}

void aw::LogObserver::restrictContext () {

    m_allContextsAllowed = false;

}
