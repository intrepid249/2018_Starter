#include "entities\weapon\Bullet.h"


Bullet::Bullet(glm::vec2 pos, const char * texFileName)
{

}

Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime)
{
	glm::vec2 velocity = glm::vec2(cosf(getRotation()) * MOVEMENT_SPEED * deltaTime, sinf(getRotation() * MOVEMENT_SPEED * deltaTime));
	m_pos += velocity;

	m_lifetime -= deltaTime;
	if (m_lifetime <= 0)
		setDrawn(false);
}
