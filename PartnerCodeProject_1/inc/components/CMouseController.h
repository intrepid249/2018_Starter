#pragma once
#include "IComponent.h"

class CMouseController : public IComponent
{
public:
	CMouseController();
	~CMouseController();

	void update(float deltaTime);

	void updateControls();
	void updatePrimaryWeapon(float deltaTime);
	void shootPrimaryWeapon();
	void updateSecondaryWeapon(float deltaTime);
	void shootSecondaryWeapon();

	void render(aie::Renderer2D *renderer);

private:
	bool m_isShootingPrimary, m_canShootPrimary, m_isShootingSecondary, m_canShootSecondary;
	float m_primaryTimer, m_secondaryTimer;
};

