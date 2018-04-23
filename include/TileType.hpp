#ifndef H_AW_TILETYPE
#define H_AW_TILETYPE

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

namespace aw {
class TileType {

public:

    TileType () = default;
    ~TileType () = default;

    TileType (TileType&&) = default;
    TileType& operator = (TileType&&) = default;

    TileType (const TileType&) = default;
    TileType& operator = (const TileType&) = default;

    sf::Sprite* getSprite ();

    bool isSolid () const;
    bool isVisible () const;

    bool is (const std::string&) const;
    bool get (const std::string&) const;

    void setSprite (sf::Sprite&&);
    void setSprite (const sf::Sprite&);

    void makeSolid ();
    void makeNonsolid ();

    void makeVisible ();
    void makeInvisible ();

    void setBool (const std::string&, bool);
    void setDouble (const std::string&, double);

private:

    sf::Sprite m_sprite;

    bool m_solid {false};
    bool m_visible {false};

    std::unordered_map<std::string, bool> m_boolMap;
    std::unordered_map<std::string, double> m_doubleMap;

};
}

#endif
