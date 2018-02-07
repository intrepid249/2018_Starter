#pragma once
class GameEntity;
namespace aie {
	class Renderer2D;
}

/* Defines the interface of components that will define the behaviours of objects*/
class IComponent {
public:
	IComponent() = default;
	virtual ~IComponent() = default;

	/** Update members and actions each frame cycle*/
	virtual void update(float deltaTime) {}
	/** Allow for displaying objects to the screen*/
	virtual void render(aie::Renderer2D *renderer) {}

	void setParent(GameEntity *parent) { m_parent = parent; }

protected:
	GameEntity *m_parent = nullptr;
};