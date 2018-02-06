#pragma once

#include <Application.h>
#include <Renderer2D.h>
#include <vector>

class Rectangle;
class Circle;

class CobwebProjectApp : public aie::Application {
public:

	CobwebProjectApp();
	virtual ~CobwebProjectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	std::vector<Rectangle*> m_blocks;
	Circle *m_ball;
	Rectangle *m_paddle;
};