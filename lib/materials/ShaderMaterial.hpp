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

#ifndef __MB_SHADER_MATERIAL__
#define __MB_SHADER_MATERIAL__

#include <mb/api.h>

#include "Material.hpp"

namespace mb
{
	typedef enum
	{
		VertexShader, FragmentShader, GeometryShader, TesselationEvaluationShader, TesselationControlShader
	} ShaderType;
	class ShaderMaterial: public Material
	{
	public:
		MB_API
		ShaderMaterial(
			const std::string& name,
			const std::vector<std::pair<ShaderType, const char*> >& shaders,
			const std::vector<std::pair<const char*, Uniform*> >& uniforms);

		MB_API
		std::string name() const
		{
			return _name;
		}
	protected:
		std::string _name;
	};
  typedef std::shared_ptr<mb::ShaderMaterial> ShaderMaterialPtr;
}

#endif /* __MB_SHADER_MATERIAL__ */
