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

#ifndef __MB_MATERIAL__
#define __MB_MATERIAL__

#include <mb/api.h>

#include <unordered_map>
#include "Uniform.hpp"
#include "../core/Program.hpp"
#include "../maths/Vect2.hpp"
#include "../maths/Vect3.hpp"
#include "../maths/Vect4.hpp"
#include "../maths/Mat2.hpp"
#include "../maths/Mat3.hpp"
#include "../maths/Mat4.hpp"

#include "../core/GLContext.hpp"

namespace mb
{
  typedef std::unordered_map<std::string, Uniform*> TUniforms;
	class Material
    : public std::enable_shared_from_this<Material>
	{
	public:
		static GLContext* _context;
		MB_API
		Material();
		MB_API
    virtual ~Material();
		MB_API
    TUniforms& uniforms();
		MB_API
    Uniform*& uniform(const std::string& name);
		MB_API
		void addUniform(const std::string& name, Uniform* u);
		MB_API
		bool hasUniform(const std::string& name);
		MB_API
		Uniform* operator[](std::string& name);
		MB_API
		virtual void use() final;
		MB_API
		virtual void unuse();

		virtual void configUse() {};

		// Depth state
		bool DepthTest;
		bool DepthWrite;
		unsigned int DepthCompare;

		// Face culling state
		bool Cull;
		unsigned int CullFace;
		unsigned CullWindingOrder;

		// Blending state
		bool Blend;
		unsigned int BlendSrc;
		unsigned int BlendDst;
		unsigned int BlendEquation;

		unsigned int PolygonMode;
	protected:
		std::string id;
		TUniforms _uniforms;
    Program* _program;
		mb::UniformType type;

	private:
		unsigned int texID;
		bool setDirty;
	};

  typedef std::shared_ptr<mb::Material> MaterialPtr;
}

#endif /* __MB_MATERIAL__ */
