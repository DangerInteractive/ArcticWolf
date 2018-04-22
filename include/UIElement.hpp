#ifndef H_AW_UIELEMENT
#define H_AW_UIELEMENT

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#ifndef H_AW_UILAYER
namespace aw { class UILayer {
    public: void onRenderCacheInvalidate ();
}; }
#endif

namespace aw {
class UIElement {

public:

    enum class SizeUnit {
        PIXEL, // |
        POINT, // |Typographic Standards
        EM,    // |
        PERCENT, // Percent of available width
        RATIO, // 1.0 equals 100%
        VIEWPORTWIDTH,  // |Viewport width (relative to window size)
        VIEWPORTHEIGHT, // |
        PARENTWIDTH,  // | Relative to parent element
        PARENTHEIGHT, // |
        SELFWIDTH, // | Relative to self (this element's content)
        SELFHEIGHT // |
    };

    UIElement () = default;
    ~UIElement () = default;

    UIElement (UIElement&&) = default;
    UIElement& operator = (UIElement&&) = default;

    UIElement (const UIElement&) = default;
    UIElement& operator = (const UIElement&) = default;

    const std::vector<std::unique_ptr<UIElement>>& getChildrenReference () const;
    std::vector<UIElement*> getChildren ();
    std::vector<UIElement*> getAll ();
    UIElement* getParent ();
    UILayer* getLayer ();

    double getZIndex () const;

    double getOffsetX () const;
    SizeUnit getOffsetXUnit () const;
    double getOffsetY () const;
    SizeUnit getOffsetYUnit () const;

    double getMarginTop () const;
    SizeUnit getMarginTopUnit () const;
    double getMarginRight () const;
    SizeUnit getMarginRightUnit () const;
    double getMarginBottom () const;
    SizeUnit getMarginBottomUnit () const;
    double getMarginLeft () const;
    SizeUnit getMarginLeftUnit () const;

    double getBorderWidthTop () const;
    SizeUnit getBorderWidthTopUnit () const;
    double getBorderWidthRight () const;
    SizeUnit getBorderWidthRightUnit () const;
    double getBorderWidthBottom () const;
    SizeUnit getBorderWidthBottomUnit () const;
    double getBorderWidthLeft () const;
    SizeUnit getBorderWidthLeftUnit () const;

    double getPaddingTop () const;
    SizeUnit getPaddingTopUnit () const;
    double getPaddingRight () const;
    SizeUnit getPaddingRightUnit () const;
    double getPaddingBottom () const;
    SizeUnit getPaddingBottomUnit () const;
    double getPaddingLeft () const;
    SizeUnit getPaddingLeftUnit () const;

    sf::Color getBorderColorTop () const;
    sf::Color getBorderColorRight () const;
    sf::Color getBorderColorBottom () const;
    sf::Color getBorderColorLeft () const;

    sf::Color getBackgroundColor () const;
    std::shared_ptr<sf::Image> getBackgroundImage () const;
    double getBackgroundImageOffsetX () const;
    SizeUnit getBackgroundImageOffsetXUnit () const;
    double getBackgroundImageOffsetY () const;
    SizeUnit getBackgroundImageOffsetYUnit () const;
    double getBackgroundImageSizeX () const;
    SizeUnit getBackgroundImageSizeXUnit () const;
    double getBackgroundImageSizeY () const;
    SizeUnit getBackgroundImageSizeYUnit () const;

    void onDirtyZIndex (UIElement*);

    bool operator < (const UIElement&) const;
    bool operator <= (const UIElement&) const;
    bool operator > (const UIElement&) const;
    bool operator >= (const UIElement&) const;
    bool operator == (const UIElement&) const;
    bool operator != (const UIElement&) const;
    template <typename T>
    bool operator < (T&& right) const {
        return (getZIndex() < std::forward<T>(right));
    }
    template <typename T>
    bool operator <= (T&& right) const {
        return (getZIndex() <= std::forward<T>(right));
    }
    template <typename T>
    bool operator > (T&& right) const {
        return (getZIndex() > std::forward<T>(right));
    }
    template <typename T>
    bool operator >= (T&& right) const {
        return (getZIndex() >= std::forward<T>(right));
    }
    template <typename T>
    bool operator == (T&& right) const {
        return (getZIndex() == std::forward<T>(right));
    }
    template <typename T>
    bool operator != (T&& right) const {
        return (getZIndex() != std::forward<T>(right));
    }

protected:

    virtual void dirtyZIndexCallback ();

    std::vector<std::unique_ptr<UIElement>> m_children;
    UIElement* m_parent;
    UILayer* m_layer;

    double m_zIndex {0.0};

    double m_offsetX {0.0};
    SizeUnit m_offsetXUnit {SizeUnit::PIXEL};
    double m_offsetY {0.0};
    SizeUnit m_offsetYUnit {SizeUnit::PIXEL};

    double m_marginTop {0.0};
    SizeUnit m_marginTopUnit {SizeUnit::PIXEL};
    double m_marginRight {0.0};
    SizeUnit m_marginRightUnit {SizeUnit::PIXEL};
    double m_marginBottom {0.0};
    SizeUnit m_marginBottomUnit {SizeUnit::PIXEL};
    double m_marginLeft {0.0};
    SizeUnit m_marginLeftUnit {SizeUnit::PIXEL};

    double m_borderWidthTop {0.0};
    SizeUnit m_borderWidthTopUnit {SizeUnit::PIXEL};
    double m_borderWidthRight {0.0};
    SizeUnit m_borderWidthRightUnit {SizeUnit::PIXEL};
    double m_borderWidthBottom {0.0};
    SizeUnit m_borderWidthBottomUnit {SizeUnit::PIXEL};
    double m_borderWidthLeft {0.0};
    SizeUnit m_borderWidthLeftUnit {SizeUnit::PIXEL};

    double m_paddingTop {0.0};
    SizeUnit m_paddingTopUnit {SizeUnit::PIXEL};
    double m_paddingRight {0.0};
    SizeUnit m_paddingRightUnit {SizeUnit::PIXEL};
    double m_paddingBottom {0.0};
    SizeUnit m_paddingBottomUnit {SizeUnit::PIXEL};
    double m_paddingLeft {0.0};
    SizeUnit m_paddingLeftUnit {SizeUnit::PIXEL};

    sf::Color m_borderColorTop {0, 0, 0, 0};
    sf::Color m_borderColorRight {0, 0, 0, 0};
    sf::Color m_borderColorBottom {0, 0, 0, 0};
    sf::Color m_borderColorLeft {0, 0, 0, 0};

    sf::Color m_backgroundColor {0, 0, 0, 0};
    std::shared_ptr<sf::Image> m_backgroundImage {nullptr};
    double m_backgroundImageOffsetX {0.0};
    SizeUnit m_backgroundImageOffsetXUnit {SizeUnit::PIXEL};
    double m_backgroundImageOffsetY {0.0};
    SizeUnit m_backgroundImageOffsetYUnit {SizeUnit::PIXEL};
    double m_backgroundImageSizeX {1.0};
    SizeUnit m_backgroundImageSizeXUnit {SizeUnit::SELFWIDTH};
    double m_backgroundImageSizeY {1.0};
    SizeUnit m_backgroundImageSizeYUnit {SizeUnit::SELFHEIGHT};

};
}

#endif
