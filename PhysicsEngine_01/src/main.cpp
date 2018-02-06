#include "PhysicsEngine_01App.h"

int main() {
	
	// allocation
	auto app = new PhysicsEngine_01App();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}