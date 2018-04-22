#ifndef H_AW_SCENESTORE
#define H_AW_SCENESTORE

#include <string>
#include <unordered_map>
#include <memory>
#include "Scene.hpp"

namespace aw {
class SceneStore {

public:

    SceneStore () = delete; // static only
    ~SceneStore () = delete;

    SceneStore (SceneStore&&) = delete;
    SceneStore& operator = (SceneStore&&) = delete;

    SceneStore (const SceneStore&) = delete;
    SceneStore& operator = (const SceneStore&) = delete;

    static bool sceneExists (const std::string&);
    static std::shared_ptr<Scene> getScene (const std::string&);

    template <typename TScene, typename ...TArg>
    static std::shared_ptr<Scene> makeScene (const std::string& key, TArg&&... args) {
        auto scene = std::make_shared<TScene>(std::forward<TArg>(args)...);
        if (registerState(key, scene)) {
            return scene;
        } else {
            return nullptr;
        }
    }
    static bool registerScene (const std::string&, const std::shared_ptr<Scene>&);
    static bool registerScene (const std::string&, Scene*);
    static void deleteScene (const std::string&);

private:

    static std::unordered_map<std::string, std::shared_ptr<Scene>> m_sceneMap;

};
}

#endif
