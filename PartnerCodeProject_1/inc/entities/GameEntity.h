#pragma once
#include <glm\glm.hpp>
#include <memory>
#include <vector>

class IComponent;

namespace aie {
	class Texture;
	class Renderer2D;
}

class GameEntity
{
public:
	GameEntity();
	GameEntity(glm::vec2 pos, const char *texFileName);
	~GameEntity();

	virtual void update(float deltaTime);
	virtual void render(aie::Renderer2D *renderer);

	void addComponent(std::shared_ptr<IComponent> component);
	template<typename T>
	T * getComponentOfType();

	const glm::vec2 &getPos();
	void setPos(glm::vec2 pos);

	const glm::vec2 &getSize();
	void setSize(glm::vec2 size);

	const glm::vec2 &getScale();
	void setScale(glm::vec2 scale);

	void setRotation(float rot);
	const float &getRotation();

	void setOrigin(glm::vec2 origin);
	const glm::vec2 &getOrigin();

	const bool &isDrawn();
	void setDrawn(bool val);

protected:
	glm::vec2 m_pos;
	glm::vec2 m_size;
	glm::vec2 m_scale;
	glm::vec2 m_origin;

	const char *m_texturePath;

	float m_rotationDir = 0; // 0 degrees is straight up

	bool m_drawn = true; // whether or not to display the object

	std::vector <std::shared_ptr<IComponent>> m_components;
};

template<typename T>
inline T * GameEntity::getComponentOfType() {
	for (auto iter = m_components.begin(); iter != m_components.end(); iter++) {
		if (dynamic_cast<T*>(*iter) != nullptr) {
			return dynamic_cast<T*>(*iter);
		}
	}
	return nullptr;
}