#ifndef H_AW_LAYER
#define H_AW_LAYER

namespace aw { class Scene; }

namespace aw {
class Layer {

public:

    Layer () = default;
    ~Layer () = default;

    Layer (Layer&&) = default;
    Layer& operator = (Layer&&) = default;

    Layer (const Layer&) = default;
    Layer& operator = (const Layer&) = default;

    Scene* getScene () const;

protected:

    Scene* m_scene {nullptr};

};
}

#endif
