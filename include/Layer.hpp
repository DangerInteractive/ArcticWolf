#ifndef H_AW_LAYER
#define H_AW_LAYER

namespace aw { class Scene; }

namespace aw {
class Layer {

public:

    Layer () = default;
    virtual ~Layer () = 0;

    Layer (Layer&&) = default;
    Layer& operator = (Layer&&) = default;

    Layer (const Layer&) = default;
    Layer& operator = (const Layer&) = default;

    Scene* getScene () const;

    double getZIndex () const;

    bool operator == (const Layer&) const;
    bool operator != (const Layer&) const;
    bool operator > (const Layer&) const;
    bool operator >= (const Layer&) const;
    bool operator < (const Layer&) const;
    bool operator <= (const Layer&) const;

protected:

    Scene* m_scene {nullptr};

    double m_zIndex {0.0};

};
}

#endif
