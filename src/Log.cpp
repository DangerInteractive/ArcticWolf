#include "../include/Log.hpp"

void aw::Log::bindUnhandledException () {

    std::set_terminate([](){
        aw::Log::error("system", "Unhandled exception.");
        std::abort();
    });

}

void aw::Log::registerObserver (std::unique_ptr<LogObserver>&& observer) {

    m_observers.push_back(std::move(observer));

}

void aw::Log::registerObserver (LogObserver* observer) {

    m_observers.emplace_back(observer);

}

std::mutex aw::Log::m_mutex;
std::vector<std::unique_ptr<aw::LogObserver>> aw::Log::m_observers {};
