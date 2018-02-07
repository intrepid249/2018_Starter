#include "components\CKeyboardController.h"
#include "entities\GameEntity.h"

#include <Input.h>


CKeyboardController::CKeyboardController()
{
}


CKeyboardController::~CKeyboardController()
{
}

void CKeyboardController::update(float deltaTime)
{
	updateKeys();
	if (m_parent != nullptr) {
		// Because bootstrap's (0, 0) coordinate is in the bottom left instead of top-left, we need to adjust the y values differently
		if (m_moveUp)
			m_parent->setPos(glm::vec2(m_parent->getPos().x, m_parent->getPos().y + m_movementSpeed * deltaTime));
		if (m_moveDown)
			m_parent->setPos(glm::vec2(m_parent->getPos().x, m_parent->getPos().y - m_movementSpeed * deltaTime));

		if (m_moveLeft)
			m_parent->setPos(glm::vec2(m_parent->getPos().x - m_movementSpeed * deltaTime, m_parent->getPos().y));
		if (m_moveRight)
			m_parent->setPos(glm::vec2(m_parent->getPos().x + m_movementSpeed * deltaTime, m_parent->getPos().y));
	}
}

void CKeyboardController::updateKeys()
{
	aie::Input *input = aie::Input::getInstance();

	if (input->isKeyDown(m_keys[UP]))
		m_moveUp = true;
	if (input->isKeyDown(m_keys[DOWN]))
		m_moveDown = true;
	if (input->isKeyDown(m_keys[LEFT]))
		m_moveLeft = true;
	if (input->isKeyDown(m_keys[RIGHT]))
		m_moveRight = true;

	if (input->isKeyUp(m_keys[UP]))
		m_moveUp = false;
	if (input->isKeyUp(m_keys[DOWN]))
		m_moveDown = false;
	if (input->isKeyUp(m_keys[LEFT]))
		m_moveLeft = false;
	if (input->isKeyUp(m_keys[RIGHT]))
		m_moveRight = false;
}

void CKeyboardController::setKeys(int upKey, int downKey, int leftKey, int rightKey)
{
	m_keys[UP] = upKey;
	m_keys[DOWN] = downKey;
	m_keys[LEFT] = leftKey;
	m_keys[RIGHT] = rightKey;
}

const int & CKeyboardController::getMovementSpeed()
{
	return m_movementSpeed;
}

void CKeyboardController::setMovementSpeed(float movementSpeed)
{
	m_movementSpeed = movementSpeed;
}
