//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2016 SuperTuxKart-Team
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include "font/bold_face.hpp"

#include "config/stk_config.hpp"
#include "font/regular_face.hpp"

// ----------------------------------------------------------------------------
BoldFace::BoldFace() : FontWithFace("BoldFace")
{
}   // BoldFace

// ----------------------------------------------------------------------------
void BoldFace::init()
{
    FontWithFace::init();
    // Reserve some space for characters added later
    m_font_max_height = m_glyph_max_height + 20;
    setFallbackFont(font_manager->getFont<RegularFace>());
    setFallbackFontScale(2.0f);

}   // init
// ----------------------------------------------------------------------------
void BoldFace::reset()
{
    FontWithFace::reset();

    core::stringw preload_chars;
    for (int i = 32; i < 128; i++)
    {
        // Include basic Latin
        preload_chars.append((wchar_t)i);
    }

    insertCharacters(preload_chars.c_str());
    updateCharactersList();
}   // reset

// ----------------------------------------------------------------------------
std::vector<std::string> BoldFace::getFacesList() const
{
    return stk_config->m_bold_faces;
}   // getFacesList
