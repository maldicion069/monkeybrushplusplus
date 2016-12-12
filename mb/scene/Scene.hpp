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

#ifndef __MB_SCENE__
#define __MB_SCENE__

#include <mb/api.h>

#include "../SimpleCamera.hpp"
#include "Node.hpp"
#include "../lights/Light.hpp"

#include <vector>

namespace mb
{
  struct Profiler
  {
    unsigned int totalMeshes;
    unsigned int totalVertices;
    unsigned int drawCalls;
    unsigned int totalIndices;
    void reset()
    {
      totalMeshes = totalVertices = drawCalls = totalIndices = 0u;
    }
  };
  class Engine;
  class Scene
  {
  public:
    MB_API
    Scene(Engine* engine, SimpleCamera* camera);
    MB_API
    ~Scene();
    MB_API
    void render(float dt);
    MB_API
    mb::NodePtr root() const;
    MB_API
    void registerBeforeRender(const std::function<void()>& cb,
      bool recyclable = false);
    MB_API
    void registerAfterRender(const std::function<void()>& cb,
      bool recyclable = false);
    MB_API
    void addLight(mb::Light* light);
    MB_API
    std::vector<mb::Light*> lights() const;
    MB_API
    bool update() const;
    MB_API
    void update(const bool upd);

    SimpleCamera* mainCamera;
  private:
    void applyQueue(std::vector<std::pair<std::function<void()>,
      bool> >& queue);
  protected:
    //SimpleCamera* camera = new SimpleCamera(Vect3(0.2f, 0.18f, 8.44f));
    std::vector<std::pair<std::function<void()>, bool>> _beforeRender;
    std::vector<std::pair<std::function<void()>, bool>> _afterRender;
	  void _subFixedUpdate(mb::NodePtr n, float dt);
    void _subUpdate(mb::NodePtr n, float dt);
    void updateCamera();
    mb::NodePtr _sceneGraph;

    std::vector<mb::Light*> _lights;

  public:
    Profiler profiler;
    bool sort = true;
  protected:
    Engine* _engine;

    Mat4 _projection;
    Mat4 _view;

    std::vector<mb::NodePtr> _batch;

  protected:
    bool _update;
	float _fixedUpdateTime = 0.0f;
  };
}

#endif /* __MB_SCENE__ */
