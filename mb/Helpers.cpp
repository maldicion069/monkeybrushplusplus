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

#include "Helpers.hpp"
#include "io/Input2.hpp"
#include "scene/Node.hpp"
#include <iostream>

namespace mb
{
	MoveComponent::MoveComponent()
		: mb::Component()
		, _delta(0.01f)
		, _sign(1)
		, _velocity(1.0f)
	{
	}
	void MoveComponent::update(float dt)
	{
		if (mb::Input2::isKeyPressed(mb::Keyboard::Key::V))
		{
			this->_velocity -= 0.1f;
			if (this->_velocity < 0.0f) this->_velocity = 0.0f;
		}
		else if (mb::Input2::isKeyPressed(mb::Keyboard::Key::B))
		{
			this->_velocity += 0.1f;
			if (this->_velocity > 10.0f) this->_velocity = 10.0f;
		}
		if (this->_delta > 2.5f || this->_delta < -2.5f)
		{
			this->_sign *= -1;
		}
		this->_delta = (this->_delta > 2.5f) ? 2.5f : this->_delta;
		this->_delta = (this->_delta < -2.5f) ? -2.5f : this->_delta;
		this->_delta += this->_velocity * this->_sign * dt;
		this->_node->transform().position().x(this->_delta);
	}
	RotateComponent::RotateComponent(Axis axis)
		: mb::Component()
		, _delta(0.01f)
		, _velocity(1.0f)
		, _rotate(false)
		, _axis(axis)
	{
	}
	/*void RotateComponent::setAxis(Axis axis)
	{
		_axis = axis;
	}*/
	void RotateComponent::update(float dt)
	{
		if (mb::Input2::isKeyClicked(mb::Keyboard::Key::Space))
		{
			this->_rotate = !this->_rotate;
		}
		if (this->_rotate)
		{
			this->_delta += this->_velocity * dt;
			switch (_axis)
			{
			case Axis::x:
				this->_node->transform().rotation().x(this->_delta);
				break;
			case Axis::y:
				this->_node->transform().rotation().y(this->_delta);
				break;
			case Axis::z:
				this->_node->transform().rotation().z(this->_delta);
				break;
			}
		}
	}
	ScaleComponent::ScaleComponent()
		: mb::Component()
		, _inc(0.0f)
	{
	}
	void ScaleComponent::update(float /*dt*/)
	{
		this->_node->transform().scale().set(
			this->_inc * 0.01,
			this->_inc * 0.01,
			this->_inc * 0.01
		);
		this->_inc += 1.0f;
	}
	PrintPosition::PrintPosition()
		: mb::Component()
	{
	}
	void PrintPosition::update(float)
	{
		mb::Vect3 pos = this->_node->transform().position();
		std::cout << "POSITION: " << pos.x() << ", " << pos.y() << ", " << pos.z() << std::endl;
	}
}
