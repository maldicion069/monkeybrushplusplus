/*
 * Copyright (c) 2016 maldicion069
 *
 * Authors: Cristian Rodríguez Bernal <ccrisrober@gmail.com>
 *
 * This file is part of MonkeyBrushPlusPlus
 * <https://github.com/maldicion069/monkeybrushplusplus>
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

#ifndef __MB_MESH_RENDERER_TESSELATION__
#define __MB_MESH_RENDERER_TESSELATION__

#include <mb/api.h>

#include "MeshRenderer.hpp"

namespace mb
{
  class MeshRendererTesselation: public MeshRenderer
  {
  public:
    MB_API
    MeshRendererTesselation(mb::DrawablePtr mesh, MaterialPtr material);
  };
}

#endif /* __MB_MESH_RENDERER_TESSELATION__ */
