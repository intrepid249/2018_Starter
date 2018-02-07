#include "PartnerCodeProject_1App.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

#include "resource_manager\ResourceManager.h"
#include "entities\GameEntity.h"
#include "components\CKeyboardController.h"

PartnerCodeProject_1App::PartnerCodeProject_1App() {

}

PartnerCodeProject_1App::~PartnerCodeProject_1App() {

}

bool PartnerCodeProject_1App::startup() {
	m_renderer = std::unique_ptr<aie::Renderer2D>(new aie::Renderer2D());

	ResourceManager::create();
	ResourceManager::getInstance()->getFonts()["main"] = std::shared_ptr<aie::Font>(new aie::Font("font/consolas.ttf", 32));

	m_object = std::unique_ptr<GameEntity>(new GameEntity(glm::vec2(10, 10), "textures/grass.png"));
	// Add a keyboard controller to the entity to control movement
	std::shared_ptr<CKeyboardController> kc = std::shared_ptr<CKeyboardController>(new CKeyboardController());
	kc->setKeys(aie::INPUT_KEY_W, aie::INPUT_KEY_S, aie::INPUT_KEY_A, aie::INPUT_KEY_D);
	kc->setMovementSpeed(175.5f);
	kc->setParent(m_object.get());
	m_object->addComponent(kc);

	return true;
}

void PartnerCodeProject_1App::shutdown() {
	ResourceManager::destroy();
}

void PartnerCodeProject_1App::update(float deltaTime) {
	// input example
	aie::Input* input = aie::Input::getInstance();

	m_object->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PartnerCodeProject_1App::draw() {
	// wipe the screen to the background colour
	clearScreen();

	// Get an instance of the Resource manager for ease of use
	ResourceManager *resourceManager = ResourceManager::getInstance();

	// begin drawing sprites
	m_renderer->begin();

	// draw your stuff here!
	m_object->render(m_renderer.get());

	
	// output some text, uses the last used colour
	m_renderer->drawText(resourceManager->getFonts()["main"].get(), "Press ESC to quit", 10, 10);

	// done drawing sprites
	m_renderer->end();
}