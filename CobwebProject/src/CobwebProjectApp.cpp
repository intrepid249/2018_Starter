#include "CobwebProjectApp.h"
#include <Texture.h>
#include <Font.h>
#include <Input.h>
#include <Gizmos.h>

#include <glm\ext.hpp>

#include "Shapes\Circle.h"
#include "Shapes\Rectangle.h"

CobwebProjectApp::CobwebProjectApp() {

}

CobwebProjectApp::~CobwebProjectApp() {

}

bool CobwebProjectApp::startup() {
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void CobwebProjectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void CobwebProjectApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();


	static const int rows = 5;
	static const int cols = 10;
	static const int hSpace = 1;
	static const int vSpace = 1;

	static const glm::vec2 scrExtents(100, 50);
	static const glm::vec2 boxExtents(7, 3);
	static const glm::vec2 startPos( // Does v and hSpace need to be swapped?
		-(cols >> 1) * ((boxExtents.x * 2) + hSpace) + boxExtents.x + (hSpace / 2.0f),
		scrExtents.y - ((boxExtents.y * 2) + vSpace)
	);


	// Setup the grid
	glm::vec2 gridPos;
	for (int y = 0; y < rows; y++) {
		gridPos = glm::vec2(startPos.x, startPos.y - (y * ((boxExtents.y * 2) + vSpace)));
		for (int x = 0; x < cols; x++) {
			m_blocks.push_back(new Rectangle(gridPos, boxExtents, RED));
			gridPos.x += (boxExtents.x * 2) + hSpace;
		}
	}
	// Add the grid to gizmo collection
	for (int i = 0; i < m_blocks.size(); i++) {
		m_blocks[i]->update(deltaTime);
	}

	// Setup the paddle
	m_paddle = new Rectangle(glm::vec2(0, -40), glm::vec2(12, 2), BLUE);
	// Add the paddle to the gizmo collection
	m_paddle->update(deltaTime);

	// Setup the ball
	m_ball = new Circle(glm::vec2(0, -35), 3, 32, GREEN);
	// Add the ball to the gizmo collection
	m_ball->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void CobwebProjectApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//Circle c(glm::vec2(0, 0), 5, 16);

	// draw your stuff here!
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.f, 1.f));
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}