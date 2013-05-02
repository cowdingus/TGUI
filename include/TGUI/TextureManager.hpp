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


#ifndef TGUI_TEXTURE_MANAGER_HPP
#define TGUI_TEXTURE_MANAGER_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <list>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct TextureData
    {
        sf::Image     image;
        sf::Texture   texture;
        std::string   filename;
        unsigned int  users;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct Texture
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Texture();

        sf::Vector2u getSize() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;

        bool isTransparentPixel(unsigned int x, unsigned int y);

        operator const sf::Sprite&() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        TextureData* data;
        sf::Sprite   sprite;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API TextureManager : public sf::NonCopyable
    {
      public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///!!! TODO: Write description
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool getTexture(const std::string& filename, Texture& texture, const sf::IntRect& rect = sf::IntRect(0, 0, 0, 0));


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///!!! TODO: Write description
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool copyTexture(const Texture& textureToCopy, Texture& newTexture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///!!! TODO: Write description
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void removeTexture(Texture& textureToRemove);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:


        std::list<TextureData> m_Data;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_TEXTURE_MANAGER_HPP
