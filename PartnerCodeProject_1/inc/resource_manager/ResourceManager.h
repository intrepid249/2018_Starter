#include <map>
#include <memory>

namespace aie {
	class Texture;
	class Font;
}

/*Singleton resource manager to be used with AIE bootstrap projects
 * used to manage shared resources across the global scope of the program*/
class ResourceManager {
public:
	static ResourceManager *getInstance();
	/* Create a singleton instance of the resource manager
	 * Must be matched with a call to destroy()*/
	static void create();
	/* Clean up memory from the singleton resource manager*/
	static void destroy();

	// Return a reference to the map of texture data
	std::map<const char *, std::shared_ptr<aie::Texture>> &getTextures();
	// Return a reference to the map of font data
	std::map<const char *, std::shared_ptr<aie::Font>> &getFonts();

private:
	ResourceManager() = default;
	~ResourceManager();

	// Single container that holds all texture resources
	static std::map<const char *, std::shared_ptr<aie::Texture>>	*m_textures;
	// Single container that holds all font resources
	static std::map<const char *, std::shared_ptr<aie::Font>>		*m_fonts;

	static ResourceManager *sm_singleton;
};