#include "entities\GameEntity.h"
#include "resource_manager\ResourceManager.h"
#include "components\IComponent.h"

#include <Texture.h>
#include <Renderer2D.h>


GameEntity::GameEntity()
{
}

GameEntity::GameEntity(glm::vec2 pos, const char *texFileName) : m_pos(pos), m_texturePath(texFileName), m_scale(glm::vec2(1, 1))
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
	if (ResourceManager::getInstance()->getTextures()[m_texturePath] != nullptr && isDrawn())
		renderer->drawSprite(ResourceManager::getInstance()->getTextures()[m_texturePath].get(), m_pos.x, m_pos.y, 
			m_size.x * m_scale.x, m_size.y * m_scale.y, m_rotationDir, 0, m_origin.x, m_origin.y);
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

const glm::vec2 & GameEntity::getScale()
{
	return m_scale;
}

void GameEntity::setScale(glm::vec2 scale)
{
	m_scale = scale;
}

void GameEntity::setRotation(float rot)
{
	m_rotationDir = rot;
}

const float & GameEntity::getRotation()
{
	return m_rotationDir;
}

void GameEntity::setOrigin(glm::vec2 origin)
{
	m_origin = origin;
}

const glm::vec2 & GameEntity::getOrigin()
{
	return m_origin;
}

const bool &GameEntity::isDrawn()
{
	return m_drawn;
}

void GameEntity::setDrawn(bool val)
{
	m_drawn = val;
}
