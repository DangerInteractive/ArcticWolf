#include "../include/SceneStore.hpp"

bool aw::SceneStore::sceneExists (const std::string& key) {

    if (m_sceneMap.find(key) == m_sceneMap.end()) {
        return false;
    } else {
        return true;
    }

}

std::shared_ptr<aw::Scene> aw::SceneStore::getScene (const std::string& key) {

    if (!sceneExists(key)) {
        return nullptr;
    }

    return m_sceneMap[key];

}

bool aw::SceneStore::registerScene (const std::string& key, const std::shared_ptr<Scene>& scene) {

    if (sceneExists(key)) {
        return false;
    }

    m_sceneMap.emplace(key, scene);
    return true;

}

bool aw::SceneStore::registerScene (const std::string& key, Scene* scene) {

    return registerScene(key, std::shared_ptr<Scene>(scene));

}

void aw::SceneStore::deleteScene (const std::string& key) {

    if (!sceneExists(key)) {
        return;
    }

    m_sceneMap[key].reset();
    m_sceneMap.erase(key);

}

std::unordered_map<std::string, std::shared_ptr<aw::Scene>> aw::SceneStore::m_sceneMap;
