/*
* Copyright (c) 2016 maldicion069
*
* Authors: Cristian Rodr�guez Bernal
*
* This file is part of MonkeyBrushPlusPlus <https://github.com/maldicion069/monkeybrushplusplus>
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License version 3.0 as published
* by the Free Software Foundation.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
*/

#ifndef __MB_TEXTURE3D__
#define __MB_TEXTURE3D__

#include "Texture.hpp"

namespace MB {
	class Texture3D : public Texture {
	public:
		Texture3D(const TexOptions& opts)
			: Texture(opts, GL_TEXTURE_3D)
		{
		}
	};
}

#endif /* __MB_TEXTURE3D__ */