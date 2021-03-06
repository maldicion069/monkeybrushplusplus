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

#ifndef __MB_WINDOW__
#define __MB_WINDOW__

#include <mb/api.h>

#include "../Includes.hpp"

namespace mb
{
  struct WindowParams
  {
    const char* title;
    int width;
    int height;
    bool displayFPS;
    bool displayMouse;
    bool debugWindowEvents;
    unsigned int minVersion;
    unsigned int maxVersion;
    bool resizable;
    unsigned int depthBufferBit;
    unsigned int multiSample;
    MB_API
    WindowParams(int width_, int height_);
  };

  class Window
  {
  public:
    Window(const WindowParams& params) : _params(params) {}
    virtual ~Window() {};
    virtual bool init() = 0;
    virtual bool isRunning() = 0;
    virtual void pollEvents() = 0;
    virtual void close() = 0;
    virtual void swapBuffers() = 0;
    virtual void setTitle(const char* title) = 0;

    virtual void* getWindow() = 0;
  protected:
    WindowParams _params;
  };

  /*class GlutWindow: public Window
  {
    void* getWindow()
    {
      return this->_handle;
    }
    GlutWindow(const WindowParams& params)
      : mb::Window(params)
    {
      _handle = nullptr;
    }
    virtual ~GlutWindow() {
      glutDestroyWindow(0);
    }
    virtual void setTitle(const char* title)
    {
      glutSetWindowTitle(title);
    }
    virtual bool init()
    {
      glutInit();
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
        glutInitWindowSize(_params.width, _params.height_);
        glutCreateWindow(_params.title);
    }

    virtual bool isRunning()
    {
      return true;
    }
    virtual void pollEvents()
    {
    }
    virtual void close()
    {
      glutDestroyWindow(0);
    }
    virtual void swapBuffers()
    {
      glutSwapBuffers();
    }
  protected:
    void* _handle;
  };*/
}

#endif /* __MB_WINDOW__ */
