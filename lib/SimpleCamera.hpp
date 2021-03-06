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

#ifndef __MB_SIMPLE_CAMERA__
#define __MB_SIMPLE_CAMERA__

#include "maths/Mathf.hpp"
#include "maths/Vect3.hpp"
#include "maths/Mat4.hpp"
#include "io/Input.hpp"
#include "core/Layer.hpp"

namespace mb
{
    class SimpleCamera
    {
	protected:
        // Camera attrs
        Vect3 position;
        Vect3 front;
        Vect3 up;
        Vect3 right;
        Vect3 worldUp;

        // Euler angles
        float yaw;
        float pitch;

        // Camera options
		float movSpeed = 1.0f; // 0.05f;
        float mouseSensivity = 0.25f;
        // bool _updateCamera = false;
        float timeElapsed;

        bool _dirty;
		
		Layer _layer;

	public:
		Layer& layer()
		{
			return _layer;
		}
        Vect3 GetPos() const
        {
            return this->position;
        }

        SimpleCamera(const Vect3& position_ = Vect3::createFromScalar(0.0f),
            const Vect3& up_ = Vect3(0.0f, 1.0f, 0.0f),
            float yaw_ = -90.0f, float pitch_ = 0.0f)
        {
            this->front = Vect3(0.0f, 0.0f, -1.0f);
            this->position = position_;
            this->worldUp = up_;
            this->yaw = yaw_;
            this->pitch = pitch_;

            this->_dirty = true;

            //this->right = new MB.Vect3();
            //this->up = new MB.Vect3();

            this->updateCameraVectors();
        }
        void update(float timeElapsed_)
		{
            this->timeElapsed = timeElapsed_;

            float speed = 1.0f;

            if (Input::isKeyPressed(mb::Keyboard::Key::LShift))
			{
                speed = 2.5f;
            }

            if (Input::isKeyPressed(mb::Keyboard::Key::W))
			{
				//std::cout << "CAMERA POSITION: " << this->GetPos().x() << ", " << this->GetPos().y() << ", " << this->GetPos().z() << std::endl;
                this->processKeyboard(4, speed);
            }
            if (Input::isKeyPressed(mb::Keyboard::Key::S))
			{
                this->processKeyboard(5, speed);
            }
            if (Input::isKeyPressed(mb::Keyboard::Key::A))
			{
                this->processKeyboard(2, speed);
            }
            if (Input::isKeyPressed(mb::Keyboard::Key::D))
			{
                this->processKeyboard(3, speed);
            }
            if (Input::isKeyPressed(mb::Keyboard::Key::E))
			{
                this->processKeyboard(0, speed);
            }
            if (Input::isKeyPressed(mb::Keyboard::Key::Q))
			{
                this->processKeyboard(1, speed);
            }
            if (Input::isKeyPressed(mb::Keyboard::Key::Up))
			{
                this->processMouseMovement(0.0f, 2.5f * speed);
            }
            if (Input::isKeyPressed(mb::Keyboard::Key::Down))
			{
                this->processMouseMovement(0.0f, -2.5f * speed);
            }
            if (Input::isKeyPressed(mb::Keyboard::Key::Left))
			{
                this->processMouseMovement(-2.5f * speed, 0.0f);
            }
            if (Input::isKeyPressed(mb::Keyboard::Key::Right))
			{
                this->processMouseMovement(2.5f * speed, 0.0f);
            }
        }
        bool _firstMouse = false;
        void processKeyboard(const short& direction, const float& speed = 1.0f)
        {
            float velocity = this->movSpeed * this->timeElapsed * speed;
            if (direction == 0)
			{
                this->position = Vect3::scaleAndAdd(this->position, this->front, velocity);
            }
			else if (direction == 1)
			{
                this->position = Vect3::scaleAndAdd(this->position, this->front, -velocity);
            }
			else if (direction == 2)
			{
                this->position = Vect3::scaleAndAdd(this->position, this->right, -velocity);
            }
			else if (direction == 3)
			{
                this->position = Vect3::scaleAndAdd(this->position, this->right, velocity);
            }
			else if (direction == 4)
			{
                this->position = Vect3::scaleAndAdd(this->position, this->up, velocity);
            }
			else if (direction == 5)
			{
                this->position = Vect3::scaleAndAdd(this->position, this->up, -velocity);
            }
            _dirty = true;
        }

        void processMouseMovement(const float& _xOffset, const float& _yOffset)
        {
            float xOffset = _xOffset * this->movSpeed * 2.0f * this->timeElapsed;
            float yOffset = _yOffset * this->movSpeed * 2.0f * this->timeElapsed;

            this->yaw += xOffset;
            this->pitch += yOffset;

            if (this->pitch > 89.0f)
            {
                this->pitch = 89.0f;
            }
            if (this->pitch < -89.0f)
            {
                this->pitch = -89.0f;
            }
            _dirty = true;
            this->updateCameraVectors();
        }
        float _fov = 45.0f;
        float fov() const
        {
            return this->_fov;
        };
        void fov(const float& f)
        {
            this->_fov = f;
        };
        float _near = 0.1f;
        float _far = 1000.0f;

        void updateCameraVectors()
        {
			this->front.set(
				std::cos(Mathf::degToRad(this->yaw)) * std::cos(Mathf::degToRad(this->pitch)),
				std::sin(Mathf::degToRad(this->pitch)),
				std::sin(Mathf::degToRad(this->yaw)) * std::cos(Mathf::degToRad(this->pitch))
			);
			this->front.normalize();

            // Recalculate right and up vector
			this->right = Vect3::cross(this->front, this->worldUp);
			this->right.normalize();
			this->up = Vect3::cross(this->right, this->front);
			this->up.normalize();

            viewMatrix();

            _dirty = true;
        }

        Mat4 _view;
        Mat4 _proj;

		Mat4 viewMatrix()
		{
            if (_dirty)
            {
                _view = Mat4::lookAt(
                this->position,
                Vect3::add(
                    this->position,
                    this->front
                ),
                this->up);
            }
			return _view;
		}
		Mat4 orthoProjectionMatrix(const unsigned int& w, const unsigned int& h)
		{
			float yMin = -0.0001f * std::tan(_fov * PI / 360.0f);
			float yMax = -yMin;
			float xMin = yMin + (w * 1.0f) / (h * 1.0f);
			float xMax = yMax + (w * 1.0f) / (h * 1.0f);
			return Mat4::orthographic(xMin, xMax, yMin, yMax, 0.1f, 1000.0f);
		}
		Mat4 projectionMatrix(const unsigned int w, const unsigned int h)
		{
            if (_dirty)
            {
                _proj = Mat4::perspective(
                    Mathf::Deg2Rad * this->_fov, w / h, this->_near, this->_far);
            }
			return _proj;
		}

		const float PI = 3.1415f;
    };
};

#endif /* __MB_SIMPLE_CAMERA__ */
