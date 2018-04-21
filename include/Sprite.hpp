#ifndef H_CLASS_SPRITE
#define H_CLASS_SPRITE

namespace aw {
class Sprite {

public:

    Sprite () = default;
    ~Sprite () = default;

    Sprite (Sprite&&) = default;
    Sprite& operator = (Sprite&&) = default;

    Sprite (const Sprite&) = default;
    Sprite& operator = (const Sprite&) = default;

private:

};
}

#endif
