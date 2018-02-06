#pragma once
#include <glm\ext.hpp>

namespace aie {
	class Renderer2D;
}

using glm::vec2;

#define RED glm::vec4(1, 0, 0, 1)
#define GREEN glm::vec4(0, 1, 0, 1)
#define BLUE glm::vec4(0, 0, 1, 1)

class Shape {
public:
	Shape() = default;
	Shape(vec2 pos, glm::vec4 colour) : m_pos(pos), m_colour(colour) {}
	virtual ~Shape() {};

	virtual void update(float deltaTime) = 0;
	virtual void draw(aie::Renderer2D *renderer) = 0;

	bool isActive() { return active; }
	void setActive(bool val) { active = val; }

protected:
	vec2 m_pos;
	glm::vec4 m_colour;
	bool active;
};