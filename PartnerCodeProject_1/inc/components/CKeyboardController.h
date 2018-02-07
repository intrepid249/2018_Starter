#pragma once
#include "IComponent.h"
#include <map>

class CKeyboardController : public IComponent
{
public:
	CKeyboardController();
	~CKeyboardController();

	void update(float deltaTime);
	void updateKeys();

	void setKeys(int upKey, int downKey, int leftKey, int rightKey);

	const int &getMovementSpeed();
	void setMovementSpeed(float movementSpeed);

private:
	enum KeyCode { UP, DOWN, LEFT, RIGHT };
	std::map<KeyCode, int> m_keys;

	bool m_moveUp = false, m_moveDown = false, m_moveLeft = false, m_moveRight = false;
	float m_movementSpeed;
};

