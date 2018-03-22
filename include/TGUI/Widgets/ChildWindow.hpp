/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2017 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_CHILD_WINDOW_HPP
#define TGUI_CHILD_WINDOW_HPP


#include <TGUI/CopiedSharedPtr.hpp>
#include <TGUI/Container.hpp>
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Renderers/ChildWindowRenderer.hpp>
#include <limits>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Child window widget
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API ChildWindow : public Container
    {
    public:

        typedef std::shared_ptr<ChildWindow> Ptr; ///< Shared widget pointer
        typedef std::shared_ptr<const ChildWindow> ConstPtr; ///< Shared constant widget pointer


        /// Title alignments, possible options for the setTitleAlignment function
        enum class TitleAlignment
        {
            Left,   ///< Places the title on the left side of the title bar
            Center, ///< Places the title in the middle of the title bar
            Right   ///< Places the title on the right side of the title bar
        };


        /// Title buttons (use bitwise OR to combine)
        enum TitleButton
        {
            None     = 0,      ///< No buttons
            Close    = 1 << 0, ///< Include a close button
            Maximize = 1 << 1, ///< Include a maximize button
            Minimize = 1 << 2  ///< Include a minimize button
        };

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChildWindow(const sf::String& title = "", unsigned int titleButtons = TitleButton::Close);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates a new child window widget
        ///
        /// @return The new child window
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static ChildWindow::Ptr create(const sf::String& title = "", unsigned int titleButtons = TitleButton::Close);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another child window
        ///
        /// @param childWindow  The other child window
        ///
        /// @return The new child window
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static ChildWindow::Ptr copy(ChildWindow::ConstPtr childWindow);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        /// @return Temporary pointer to the renderer that may be shared with other widgets using the same renderer
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChildWindowRenderer* getSharedRenderer();
        const ChildWindowRenderer* getSharedRenderer() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        /// @return Temporary pointer to the renderer
        /// @warning After calling this function, the widget has its own copy of the renderer and it will no longer be shared.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ChildWindowRenderer* getRenderer();
        const ChildWindowRenderer* getRenderer() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the position of the widget
        ///
        /// This function completely overwrites the previous position.
        /// See the move function to apply an offset based on the previous position instead.
        /// The default position of a transformable widget is (0, 0).
        ///
        /// @param position New position
        ///
        /// @see move, getPosition
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setPosition(const Layout2d& position) override;
        using Widget::setPosition;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the child window
        ///
        /// @param size   Sets the new size of the child window
        ///
        /// This is the size of the child window, without the title bar nor the borders.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(const Layout2d& size) override;
        using Widget::setSize;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the full child window
        ///
        /// @return Size of the child window
        ///
        /// The size returned by this function is the size of the child window, including the title bar and the borders.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getFullSize() const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the maximum size of the child window.
        ///
        /// @param size   Sets the new maximum size of the child window
        ///
        /// This function sets the maximum size of the window excluding borders and titlebar.
        /// If the window is larger than the new maximum size, it will automatically be resized down.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMaximumSize(Vector2f size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the maximum size of the child window.
        ///
        /// @return Maximum size of the child window
        ///
        /// The size returned by this function is the maximum size of the child window, excluding the title bar and the borders.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getMaximumSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the minimum size of the child window.
        ///
        /// @param size   Sets the new minimum size of the child window
        ///
        /// This function sets the minimum size of the window excluding borders and titlebar.
        /// If the window is smaller than the new minimum size, it will automatically be resized up.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMinimumSize(Vector2f size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the minimum size of the child window.
        ///
        /// @return Minimum size of the child window
        ///
        /// The size returned by this function is the minimum size of the child window, excluding the title bar and the borders.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getMinimumSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the title that is displayed in the title bar of the child window
        ///
        /// @param title  New title for the child window
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTitle(const sf::String& title);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the title that is displayed in the title bar of the child window
        ///
        /// @return Title of the child window
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const sf::String& getTitle() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the character size of the title
        /// @param size  The new title text size.
        ///              If the size is set to 0 then the character size is determined by the height of the title bar.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTitleTextSize(unsigned int size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the character size of the title
        /// @return The current title text size
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getTitleTextSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the title alignment
        ///
        /// @param alignment  How should the title be aligned in the title bar?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTitleAlignment(TitleAlignment alignment);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the title alignment
        ///
        /// @return How the title is aligned in the title bar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TitleAlignment getTitleAlignment() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the title buttons
        ///
        /// @param buttons  Which buttons should be available in the title bar?
        ///
        /// By default ChildWindows only display a close button. You may set the window to show a combination of buttons.
        /// For example, the following will set the ChildWindow to have both a minimize and close button.
        /// @code
        /// childWindow->setTitleButtons(ChildWindow::TitleButtons::Minimize | ChildWindow::TitleButtons::Close);
        /// @endcode
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTitleButtons(unsigned int buttons);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the title bar buttons
        ///
        /// @return Which buttons are available in the title bar
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getTitleButtons() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Destroys the window
        ///
        /// When no callback is requested when closing the window, this function will be called automatically.
        ///
        /// When you requested a callback then you get the opportunity to cancel the closing of the window.
        /// If you want to keep it open then don't do anything, if you want to close it then just call this function.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void destroy();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes whether the child window can be resized by dragging its borders or not
        ///
        /// @param resizable  Can the user change the size of the window by dragging one of the borders?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setResizable(bool resizable = true);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Checks whether the child window can be resized by dragging its borders or not
        ///
        /// @return Can the user change the size of the window by dragging one of the borders?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isResizable() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the child window to be kept inside its parent
        ///
        /// @param enabled  When it's set to true, the child window will always be kept automatically inside its parent.
        ///                 It will be fully kept on left, right and top.
        ///                 At the bottom of the parent only the title bar will be kept inside.
        ///                 It's set to false by default
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void keepInParent(bool enabled = true);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Tells whether the child window is kept inside its parent
        ///
        /// @return  When it's set to true, the child window will always be kept automatically inside its parent.
        ///          It will be fully kept on left, right and top.
        ///          At the bottom of the parent only the title bar will be kept inside.
        ///          It's set to false by default
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isKeptInParent() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the distance between the position of the container and a widget that would be drawn inside
        ///        this container on relative position (0,0).
        ///
        /// @return Offset of the widgets in the container
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getChildWidgetsOffset() const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// This function is called when the widget is added to a container.
        /// You should not call this function yourself.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setParent(Container* parent) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the mouse position (which is relative to the parent widget) lies on top of the widget
        ///
        /// @return Is the mouse on top of the widget?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool mouseOnWidget(Vector2f pos) const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void leftMousePressed(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void leftMouseReleased(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseMoved(Vector2f pos) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseNoLongerOnWidget() override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseNoLongerDown() override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Draw the widget to a render target
        ///
        /// @param target Render target to draw to
        /// @param states Current render states
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Updates the title bar texture, text and buttons after the title bar height has changed.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateTitleBarHeight();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves a signal based on its name
        ///
        /// @param signalName  Name of the signal
        ///
        /// @return Signal that corresponds to the name
        ///
        /// @throw Exception when the name does not match any signal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Signal& getSignal(std::string signalName) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Function called when one of the properties of the renderer is changed
        ///
        /// @param property  Lowercase name of the property that was changed
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void rendererChanged(const std::string& property) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Saves the widget as a tree node in order to save it to a file
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<DataIO::Node> save(SavingRenderersMap& renderers) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads the widget from a tree of nodes
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void load(const std::unique_ptr<DataIO::Node>& node, const LoadingRenderersMap& renderers) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Widget::Ptr clone() const override
        {
            return std::make_shared<ChildWindow>(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public:

        Signal            onMousePress = {"MousePressed"};  ///< The mouse went down on the widget
        SignalChildWindow onClose      = {"Closed"};        ///< The window was closed. Optional parameter: pointer to the window
        SignalChildWindow onMinimize   = {"Minimized"};     ///< The window was minimized. Optional parameter: pointer to the window
        SignalChildWindow onMaximize   = {"Maximized"};     ///< The window was maximized. Optional parameter: pointer to the window


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        enum ResizeDirection
        {
            ResizeNone   = 0,
            ResizeLeft   = 1,
            ResizeTop    = 2,
            ResizeRight  = 4,
            ResizeBottom = 8
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        Text           m_titleText;
        Vector2f       m_draggingPosition;
        Vector2f       m_maximumSize    = {std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity()};
        Vector2f       m_minimumSize    = {0, 0};
        TitleAlignment m_titleAlignment = TitleAlignment::Center;
        unsigned int   m_titleButtons   = TitleButton::Close;
        unsigned int   m_titleTextSize  = 0;

        CopiedSharedPtr<Button> m_closeButton;
        CopiedSharedPtr<Button> m_minimizeButton;
        CopiedSharedPtr<Button> m_maximizeButton;

        bool m_mouseDownOnTitleBar = false;
        bool m_keepInParent = false;

        bool m_resizable = false;
        int m_resizeDirection = ResizeNone;

        Sprite m_spriteTitleBar;

        // Cached renderer properties
        Borders m_bordersCached;
        Color   m_borderColorCached;
        Color   m_titleColorCached;
        Color   m_titleBarColorCached;
        Color   m_backgroundColorCached;
        float   m_titleBarHeightCached = 20;
        float   m_distanceToSideCached = 0;
        float   m_paddingBetweenButtonsCached = 0;
        bool    m_showTextOnTitleButtonsCached = false;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_CHILD_WINDOW_HPP
