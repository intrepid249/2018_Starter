#pragma once
#include "Shape.h"

class Circle : Shape {
public:
	Circle(vec2 pos, float radius, unsigned int segments, glm::vec4 colour);
	virtual ~Circle();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D *renderer);

protected:
	float m_radius;
	unsigned int m_segments;
};