#include "Shapes\Circle.h"

#include <Renderer2D.h>
#include <Gizmos.h>

Circle::Circle(vec2 pos, float radius, unsigned int segments, glm::vec4 colour) : Shape(pos, colour), m_radius(radius), m_segments(segments)
{
}

Circle::~Circle()
{
}

void Circle::update(float deltaTime)
{
	aie::Gizmos::add2DCircle(m_pos, m_radius, m_segments, m_colour);
}

void Circle::draw(aie::Renderer2D * renderer)
{
}
