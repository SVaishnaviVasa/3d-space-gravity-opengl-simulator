#include "rendering/baseModels/cube.h"
#include "rendering/renderer.h"
#include "rendering/baseModels/sphere.h"
#include "rendering/color.h"

#include "ui/ui_manager.h"
#include "universe/scene_loader.h"

int main(void)
{
	if (!renderer::init()) {
		std::cout << "Failed to initialize renderer!" << std::endl;
		return -1;
	}

	GLFWwindow* window = renderer::getWindow();

	Universe* universe = loadScene("Scenes\\default.scene");

	renderer::setUniverse(universe);
	ui::setupUIPanels();

	while (!glfwWindowShouldClose(window)) {
		renderer::renderAll();
	}

	delete renderer::loadedUniverse;

	renderer::terminate();
	ui::fontRendering::dispose();

	ui::disposeUI();
	
	return 0;
}