#ifndef H_AW_TILEPLANE
#define H_AW_TILEPLANE

#include <array>
#include <memory>
#include <functional>

namespace aw {
template <unsigned int Width, unsigned int Height, unsigned short TileSize, unsigned short PixelSize = 1>
class TilePlane {

public:

    typedef std::function <unsigned int(unsigned int, unsigned int)> Initializer;

    TilePlane () = default;
    explicit TilePlane (unsigned int defaultValue) : m_blocks(defaultValue) {}
    ~TilePlane () = default;

    TilePlane (TilePlane&&) = default;
    TilePlane& operator = (TilePlane&&) = default;

    TilePlane (const TilePlane&) = delete;
    TilePlane& operator = (const TilePlane&) = delete;

    static constexpr unsigned int getWidth () {
        return Width;
    }

    static constexpr unsigned int getHeight () {
        return Height;
    }

    static constexpr unsigned short getTileSize () {
        return TileSize;
    }

    static constexpr unsigned short getPixelSize () {
        return PixelSize;
    }

    unsigned int get (unsigned int x, unsigned int y) const {
        return m_blocks[Width * y + x];
    }

    static constexpr unsigned int subdivide (double coordinate) {
        return static_cast<unsigned int>(coordinate / (TileSize * PixelSize));
    }

    unsigned int getByCoordinate (double x, double y) const {
        return m_blocks[Width * subdivide(y) + subdivide(x)];
    }

    void set (unsigned int value, unsigned int x, unsigned int y) {
        m_blocks[Width * y + x] = value;
    }

    void initialize (const Initializer& initializer) {
        for (unsigned int y; y < Height; ++y) {
            for (unsigned int x; x < Width; ++x) {
                m_blocks[y * Width + x] = initializer(x, y);
            }
        }
    }

private:

    std::unique_ptr<std::array<unsigned int, Width*Height>> m_blocks;

};
}

#endif
