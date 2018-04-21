#include "../include/File.hpp"

aw::File::File (const std::string& path)
: m_path(path) {}

aw::File::File (const std::string& path, std::ios_base::openmode openFlags)
: m_path(path), m_flags(openFlags) {}

bool aw::File::isOpen () const {

    return m_fstream.is_open();

}

std::string aw::File::readString () {

    std::unique_lock<std::mutex> fstream_lock(m_fstream_mutex);

    if (!isOpen()) {
        return NULL;
    }

    if (!readEnabled()) {
        return NULL;
    }

    std::ostringstream oss;
    oss << m_fstream.rdbuf();
    return oss.str();

}

bool aw::File::open () {

    std::scoped_lock lock(m_metadata_mutex, m_fstream_mutex);

    if (isOpen()) {
        return true;
    }

    m_fstream.open(m_path, m_flags);

    return isOpen();

}

bool aw::File::close () {

    std::scoped_lock lock(m_metadata_mutex, m_fstream_mutex);

    if (!isOpen()) {
        return true;
    }

    m_fstream.close();

    return !isOpen();

}

std::string aw::File::getPath () const {

    return m_path;

}

bool aw::File::setPath (const std::string& path) {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_path = path;

    return true;

}

bool aw::File::readEnabled () const {

    return m_flags & ENABLE_READ;

}

bool aw::File::enableRead () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags |= ENABLE_READ;

    return true;

}

bool aw::File::disableRead () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags &= ~ENABLE_READ;

    return true;

}

bool aw::File::writeEnabled () const {

    return m_flags & ENABLE_WRITE;

}

bool aw::File::enableWrite () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags |= ENABLE_WRITE;

    return true;

}

bool aw::File::disableWrite () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags &= ~ENABLE_WRITE;

    return true;

}

bool aw::File::appendEnabled () const {

    return m_flags & ENABLE_APPEND;

}

bool aw::File::enableAppend () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags |= ENABLE_APPEND;

    return true;

}

bool aw::File::disableAppend () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags &= ~ENABLE_APPEND;

    return true;

}

bool aw::File::atEndEnabled () const {

    return m_flags & ENABLE_AT_END;

}

bool aw::File::enableAtEnd () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags |= ENABLE_AT_END;

    return true;

}

bool aw::File::disableAtEnd () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags &= ~ENABLE_AT_END;

    return true;

}

bool aw::File::binaryEnabled () const {

    return m_flags & ENABLE_BINARY;

}

bool aw::File::enableBinary () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags |= ENABLE_BINARY;

    return true;

}

bool aw::File::disableBinary () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags &= ~ENABLE_BINARY;

    return true;

}

bool aw::File::wipeEnabled () const {

    return m_flags & ENABLE_WIPE;

}

bool aw::File::enableWipe () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags |= ENABLE_WIPE;

    return true;

}

bool aw::File::disableWipe () {

    std::unique_lock<std::mutex> metadata_lock(m_metadata_mutex);

    if (isOpen()) {
        return false;
    }

    m_flags &= ~ENABLE_WIPE;

    return true;

}
