#ifndef H_AW_POINTERLESS
#define H_AW_POINTERLESS

namespace aw {
template <typename T>
class PointerLess {

public:

    bool operator () (T left, T right) {

        return *left < *right;

    }

};
}

#endif
