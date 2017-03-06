/*
* Copyright (c) 2016 maldicion069
*
* Authors: Cristian Rodríguez Bernal <ccrisrober@gmail.com>
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

#ifndef __MB_HAS_PARENT_EXCEPTION__
#define __MB_HAS_PARENT_EXCEPTION__

#include <mb/api.h>

#include <stdexcept>
#include <string>

namespace mb
{
	class HasParentException: public Exception
	{
	public:
	    MB_API
		HasParentException( std::string childName, 
			std::string parentName, std::string targetName )
			: Exception( "Cannot attach node (\"" + childName + 
				"\") to (\"" + targetName + 
				"\") because it already has a parent (\"" + 
				parentName + "\")" )
		{
		}
	};
}

#endif /* __MB_HAS_PARENT_EXCEPTION__ */
