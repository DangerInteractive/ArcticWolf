#include "../include/TileSet.hpp"

aw::TileType* aw::TileSet::getTileType (TileStorageType key) {

    return &m_tileTypes[key];

}

bool aw::TileSet::addTileType (TileStorageType key, const TileType& type) {

    if (m_tileTypes.find(key) != m_tileTypes.end()) {
        return false;
    }

    m_tileTypes[key] = type;

    return true;

}
