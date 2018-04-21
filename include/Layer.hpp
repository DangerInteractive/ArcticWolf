#ifndef H_CLASS_LAYER
#define H_CLASS_LAYER

namespace aw {
class Layer {

public:

    Layer () = default;
    ~Layer () = default;

    Layer (Layer&&) = default;
    Layer& operator = (Layer&&) = default;

    Layer (const Layer&) = default;
    Layer& operator = (const Layer&) = default;

protected:

};
}

#endif
