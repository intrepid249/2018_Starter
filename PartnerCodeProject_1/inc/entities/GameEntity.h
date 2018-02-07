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

	void update(float deltaTime);
	void render(aie::Renderer2D *renderer);

	void addComponent(std::shared_ptr<IComponent> component);
	template<typename T>
	T * getComponentOfType();

	const glm::vec2 &getPos();
	void setPos(glm::vec2 pos);

	const glm::vec2 &getSize();
	void setSize(glm::vec2 size);

protected:
	glm::vec2 m_pos;
	glm::vec2 m_size;
	const char *m_texturePath;

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