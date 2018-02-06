#include "Shapes\Rectangle.h"

#include <Gizmos.h>

Rectangle::Rectangle(vec2 pos, vec2 size, glm::vec4 colour) : Shape(pos, colour), m_size(size)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::update(float deltaTime)
{
	aie::Gizmos::add2DAABBFilled(m_pos, m_size, m_colour);
}

void Rectangle::draw(aie::Renderer2D * renderer)
{
}
