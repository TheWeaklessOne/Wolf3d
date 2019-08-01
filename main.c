#include <stdio.h>
#include "../Vulkan/include/vulkan/vulkan.h"
#include "../SDL2/include/SDL.h"

int main() {
	printf("%zo %d", SDL_MESSAGEBOX_ERROR, VK_ERROR_DEVICE_LOST);
	return 0;
}