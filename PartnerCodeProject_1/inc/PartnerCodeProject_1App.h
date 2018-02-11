#pragma once

#include "Application.h"
#include "Renderer2D.h"

#include <memory>

class GameEntity;
class Player;

class PartnerCodeProject_1App : public aie::Application {
public:

	PartnerCodeProject_1App();
	virtual ~PartnerCodeProject_1App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	std::unique_ptr<aie::Renderer2D>	m_renderer;

	std::unique_ptr<Player> m_player;
};