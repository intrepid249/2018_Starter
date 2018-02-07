#include "entities\GameEntity.h"
#include "resource_manager\ResourceManager.h"
#include "components\IComponent.h"

#include <Texture.h>
#include <Renderer2D.h>


GameEntity::GameEntity()
{
}

GameEntity::GameEntity(glm::vec2 pos, const char *texFileName) : m_pos(pos), m_texturePath(texFileName)
{
	ResourceManager *rm = ResourceManager::getInstance();
	rm->getTextures()[texFileName] = std::shared_ptr<aie::Texture>(new aie::Texture(texFileName));
	if (rm->getTextures()[texFileName] != nullptr) {
		// If the texture is valid, then set the entity's size to that of the sprite
		setSize(glm::vec2(rm->getTextures()[texFileName]->getWidth(), rm->getTextures()[texFileName]->getHeight()));
	}
}


GameEntity::~GameEntity()
{
}

void GameEntity::update(float deltaTime)
{
	for (size_t i = 0; i < m_components.size(); i++)
		m_components[i]->update(deltaTime);
}

void GameEntity::render(aie::Renderer2D * renderer)
{
	if (ResourceManager::getInstance()->getTextures()[m_texturePath] != nullptr)
		renderer->drawSprite(ResourceManager::getInstance()->getTextures()[m_texturePath].get(), m_pos.x, m_pos.y);
}

void GameEntity::addComponent(std::shared_ptr<IComponent> component)
{
	m_components.push_back(std::move(component));
}

const glm::vec2 & GameEntity::getPos()
{
	return m_pos;
}

void GameEntity::setPos(glm::vec2 pos)
{
	m_pos = pos;
}

const glm::vec2 & GameEntity::getSize()
{
	return m_size;
}

void GameEntity::setSize(glm::vec2 size)
{
	m_size = size;
}
