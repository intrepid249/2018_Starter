#include "components\CMouseController.h"
#include "entities\GameEntity.h"
#include <Renderer2D.h>
#include <Input.h>


CMouseController::CMouseController()
{
}


CMouseController::~CMouseController()
{
}

void CMouseController::update(float deltaTime)
{
	// Get the input and store the mouse coordinates
	aie::Input *input = aie::Input::getInstance();
	int mouseX, mouseY;
	input->getMouseXY(&mouseX, &mouseY);

	// Construct a vector to the player
	mouseX -= m_parent->getPos().x;
	mouseY -= m_parent->getPos().y;

	// Rotate the player using the vector toward the mouse coordinates
	m_parent->setRotation(atan2(mouseY, mouseX));
}

void CMouseController::updateControls()
{
}

void CMouseController::updatePrimaryWeapon(float deltaTime)
{
}

void CMouseController::shootPrimaryWeapon()
{
}

void CMouseController::updateSecondaryWeapon(float deltaTime)
{
}

void CMouseController::shootSecondaryWeapon()
{
}

void CMouseController::render(aie::Renderer2D * renderer)
{
}
