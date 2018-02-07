#include "PartnerCodeProject_1App.h"

int main() {
	
	// allocation
	auto app = new PartnerCodeProject_1App();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}