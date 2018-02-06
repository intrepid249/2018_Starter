#pragma once
#include "Shape.h"

class Rectangle : Shape {
public:
	Rectangle(vec2 pos, vec2 size, glm::vec4 colour);
	virtual ~Rectangle();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D *renderer);

protected:
	vec2 m_size;
};