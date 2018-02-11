#pragma once
#include "entities\GameEntity.h"

class Player : public GameEntity
{
public:
	Player(glm::vec2 pos, const char *texFileName);
	~Player();

	virtual void update(float deltaTime);
	virtual void render(aie::Renderer2D *renderer);

private:

};

