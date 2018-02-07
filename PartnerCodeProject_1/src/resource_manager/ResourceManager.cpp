#include "resource_manager\ResourceManager.h"

// Instantiate static member variables
ResourceManager *ResourceManager::sm_singleton = nullptr;
std::map<const char *, std::shared_ptr<aie::Texture>> *ResourceManager::m_textures = new std::map<const char *, std::shared_ptr<aie::Texture>>();
std::map<const char *, std::shared_ptr<aie::Font>> *ResourceManager::m_fonts = new std::map<const char *, std::shared_ptr<aie::Font>>();

ResourceManager * ResourceManager::getInstance()
{
	return sm_singleton;
}

void ResourceManager::create()
{
	if (sm_singleton == nullptr) sm_singleton = new ResourceManager();
	return;
}

void ResourceManager::destroy()
{
	delete sm_singleton;
	sm_singleton = nullptr;
}

std::map<const char*, std::shared_ptr<aie::Texture>> &ResourceManager::getTextures()
{
	return *m_textures;
}

std::map<const char*, std::shared_ptr<aie::Font>> &ResourceManager::getFonts()
{
	return *m_fonts;
}

ResourceManager::~ResourceManager()
{
	m_textures->clear();
}
