#pragma once
#include "entities\GameEntity.h"

class Bullet : public GameEntity
{
public:
	Bullet(glm::vec2 pos, const char *texFileName);
	~Bullet();

	void update(float deltaTime);

private:
	const float MOVEMENT_SPEED = 320.f;
	float m_lifetime;
};

