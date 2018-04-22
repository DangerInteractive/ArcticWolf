#include "../include/GameStateStore.hpp"

bool aw::GameStateStore::stateExists (const std::string& key) {

    if (m_stateMap.find(key) == m_stateMap.end()) {
        return false;
    } else {
        return true;
    }

}

std::shared_ptr<aw::GameState> aw::GameStateStore::getState (const std::string& key) {

    if (!stateExists(key)) {
        return nullptr;
    }

    return m_stateMap[key];

}

bool aw::GameStateStore::registerState (const std::string& key, const std::shared_ptr<GameState>& gameState) {

    if (stateExists(key)) {
        return false;
    }

    m_stateMap.emplace(key, gameState);
    return true;

}

bool aw::GameStateStore::registerState (const std::string& key, GameState* gameState) {

    return registerState(key, std::shared_ptr<GameState>(gameState));

}

void aw::GameStateStore::deleteState (const std::string& key) {

    if (!stateExists(key)) {
        return;
    }

    m_stateMap[key].reset();
    m_stateMap.erase(key);

}

std::unordered_map<std::string, std::shared_ptr<aw::GameState>> aw::GameStateStore::m_stateMap;
