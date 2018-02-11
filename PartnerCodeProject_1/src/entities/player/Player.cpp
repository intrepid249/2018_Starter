#include "entities\player\Player.h"
#include "components\CKeyboardController.h"
#include "components\CMouseController.h"

#include <Input.h>
#include <Renderer2D.h>


Player::Player(glm::vec2 pos, const char * texFileName) : GameEntity(pos, texFileName)
{
	// Add a keyboard controller component to the player
	std::shared_ptr<CKeyboardController> kc = std::shared_ptr<CKeyboardController>(new CKeyboardController());
	kc->setKeys(aie::INPUT_KEY_W, aie::INPUT_KEY_S, aie::INPUT_KEY_A, aie::INPUT_KEY_D);
	kc->setMovementSpeed(175.5f);
	kc->setParent(this);
	addComponent(kc);

	// Add a mouse controller component to the player
	std::shared_ptr<CMouseController> mc = std::shared_ptr<CMouseController>(new CMouseController());
	mc->setParent(this);
	addComponent(mc);
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	GameEntity::update(deltaTime);

}

void Player::render(aie::Renderer2D * renderer)
{
	GameEntity::render(renderer);
#ifdef _DEBUG
	renderer->drawCircle(m_pos.x, m_pos.y, 2);
#endif // _DEBUG

}
