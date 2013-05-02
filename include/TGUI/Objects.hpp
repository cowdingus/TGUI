/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012 Bruno Van de Velde (vdv_b@tgui.eu)
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


#ifndef TGUI_OBJECTS_HPP
#define TGUI_OBJECTS_HPP

#include <TGUI/Callback.hpp>
#include <TGUI/Group.hpp>
#include <TGUI/SharedObjectPtr.hpp>
#include <TGUI/ConfigFile.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class Group;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief The parent class for every object.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API Object : public sf::Drawable, public sf::Transformable, public CallbackManager
    {
      public:

        typedef SharedObjectPtr<Object> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Object();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Object(const Object& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~Object();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Object& operator= (const Object& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the object by just calling the copy constructor.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Object* clone() = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the object.
        ///
        /// \return Size of the object
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getSize() const = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the object, after the scaling transformation.
        ///
        /// \return Size of the object
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getScaledSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Shows the object.
        ///
        /// The object won't receive events nor will it be drawn when hidden. The object is visible by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void show();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Hides the object.
        ///
        /// The object won't receive events nor will it be drawn when hidden. The object is visible by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void hide();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is visible.
        ///
        /// \return Is the object visible?
        ///
        /// If this function returns false then the object is hidden, which means that it won't receive events and it won't be drawn.
        /// All objects are visible by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool isVisible() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Enables the object.
        ///
        /// The object will receive events and send callbacks again.
        /// All objects are enabled by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void enable();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Disables the object.
        ///
        /// The object will no longer receive events and it will thus no longer send callbacks.
        /// All objects are enabled by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void disable();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is enabled.
        ///
        /// \return Is the object enabled?
        ///
        /// If this function returns false then the object is disabled and will longer receive events and it will thus no longer send callbacks.
        /// All objects are enabled by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool isEnabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is disabled.
        ///
        /// \return Is the object disabled?
        ///
        /// This means that the object will longer receive events and it will thus no longer send callbacks.
        /// All objects are enabled by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool isDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is loaded successfully.
        ///
        /// \return Is the object loaded?
        ///
        /// When an object is not loaded correctly then it will not be drawn.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool isLoaded() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Focus the object.
        ///
        /// The previously focused object will be unfocused.
        ///
        /// \see unfocus
        /// \see focusNextObject
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void focus();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Unfocus the object.
        ///
        /// \see focus
        /// \see focusNextObject
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void unfocus();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Focus the next object.
        ///
        /// Similar to unfocus, but another object will gain the focus.
        ///
        /// \see focus
        /// \see unfocus
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void focusNextObject();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns true when the object is focused and false otherwise.
        ///
        /// \return Is the object focused?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool isFocused() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the type of the object.
        ///
        /// \return Type of the object
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ObjectTypes getObjectType() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns a pointer to the parent object.
        ///
        /// \return Pointer to the parent.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Group* getParent() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Places the object before all other objects.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void moveToFront();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Places the object behind all other objects.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void moveToBack();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the callback id of the object.
        ///
        /// \param callbackId  The new callback id
        ///
        /// When receiving callback in a function which takes a Callback as parameter (or when polling the callbacks),
        /// you can find a callbackId in this Callback struct which can identify the object.
        /// This function changes the id that this object sends on a callback.
        ///
        /// By default, the callback id will be 0.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setCallbackId(unsigned int callbackId);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the callback id of the object.
        ///
        /// \return Callback id
        ///
        /// \see setCallbackId
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int getCallbackId();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called right after the elapsed time is changed.
        // The elapsed time is only changed when the object has set m_AnimatedObject to true.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void update();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // The objects use this function to send their callbacks to their parent and/or to a callback function.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void addCallback();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called when the mouse enters the object. If requested, a callback will be send.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseEnteredObject();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called when the mouse leaves the object. If requested, a callback will be send.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void mouseLeftObject();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Get the ObjectPhases from the string read from the info file.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void extractPhases(std::string phases);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Used to communicate with EventManager.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnObject(float x, float y) = 0;
        virtual void leftMousePressed(float x, float y);
        virtual void leftMouseReleased(float x, float y);
        virtual void mouseMoved(float x, float y);
        virtual void keyPressed(sf::Keyboard::Key key);
        virtual void textEntered(sf::Uint32 key);
        virtual void mouseWheelMoved(int delta);
        virtual void objectFocused();
        virtual void objectUnfocused();
        virtual void mouseNotOnObject();
        virtual void mouseNoLongerDown();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called when the object is added to a group.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void initialize(tgui::Group *const group);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Rotation is not supported in tgui objects.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setRotation(float angle);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Rotation is not supported in tgui objects.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void rotate(float angle);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        enum ObjectCallbacks
        {
            None = 0,
            Focused = 1,
            Unfocused = 2,
            MouseEntered = 4,
            MouseLeft = 8,
            ObjectCallbacksCount = 16
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        // When an object is disabled, it will no longer receive events
        bool m_Enabled;

        // Is the object visible? When it is invisible it will not receive events and it won't be drawn.
        bool m_Visible;

        // This bool will be true from the moment that the load function is completed successfully.
        bool m_Loaded;

        // This will store the different phases that the object can have
        // e.g. if there isn't a mouse down image then a button should not try to change its image on mouse down
        unsigned char m_ObjectPhase;

        // This will point to our parent object. If there is no parent then this will be NULL.
        Group* m_Parent;

        // Is the mouse on top of the object? Did the mouse go down on the object?
        bool m_MouseHover;
        bool m_MouseDown;

        // Are you focused on the object?
        bool m_Focused;

        // Can the object be focused?
        bool m_AllowFocus;

        // Keep track of the elapsed time.
        bool m_AnimatedObject;
        sf::Time m_AnimationTimeElapsed;

        // This is set to true for objects that have something to be dragged around (e.g. sliders and scrollbars)
        bool m_DraggableObject;

        // This is set to true for objects that store other objects inside them
        bool m_GroupObject;

        // Instead of creating a new object every time, one callback object is always reused
        Callback m_Callback;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        friend class EventManager;
        friend class Group;
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Parent class for every object that has borders.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API ObjectBorders
    {
      public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ObjectBorders();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the borders.
        ///
        /// \param leftBorder    Size of the left border
        /// \param topBorder     Size of the top border
        /// \param rigthBorder   Size of the right border
        /// \param bottomBorder  Size of the bottom border
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setBorders(unsigned int leftBorder = 0,  unsigned int topBorder = 0,
                                unsigned int rightBorder = 0, unsigned int bottomBorder = 0) = 0;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the borders as a tgui::Vector4u.
        ///
        /// \return border sizes
        ///
        /// The first element will be the size of the left border, the seconds is the size of the top border,
        /// the third is the size of the right border and the the last constains the size of the bottom border.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector4u getBorders() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        unsigned int m_LeftBorder;
        unsigned int m_TopBorder;
        unsigned int m_RightBorder;
        unsigned int m_BottomBorder;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_OBJECTS_HPP
