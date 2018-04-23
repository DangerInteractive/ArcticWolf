#ifndef H_AW_TILESET
#define H_AW_TILESET

#include <unordered_map>
#include "TileType.hpp"

namespace aw {
class TileSet {

public:

    typedef unsigned int TileStorageType;

    TileSet () = default;
    ~TileSet () = default;

    TileSet (TileSet&&) = default;
    TileSet& operator = (TileSet&&) = default;

    TileSet (const TileSet&) = default;
    TileSet& operator = (const TileSet&) = default;

    TileType* getTileType (TileStorageType);

    bool addTileType (TileStorageType, const TileType&);

private:

    std::unordered_map<TileStorageType, TileType> m_tileTypes;

};
}

#endif
