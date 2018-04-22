#ifndef H_AW_POINTERGREATER
#define H_AW_POINTERGREATER

namespace aw {
template <typename T>
class PointerGreater {

public:

    bool operator () (T left, T right) {

        return *left > *right;

    }

};
}

#endif
