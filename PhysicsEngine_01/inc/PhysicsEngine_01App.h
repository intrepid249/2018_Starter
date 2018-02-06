#pragma once

#include "Application.h"
#include <glm/mat4x4.hpp>

class PhysicsEngine_01App : public aie::Application {
public:

	PhysicsEngine_01App();
	virtual ~PhysicsEngine_01App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	// camera transforms
	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};