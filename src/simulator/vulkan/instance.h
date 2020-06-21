#ifndef INSTANCE_H
#define INSTANCE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <string.h>
#include "defines.h"
#include "debugCommon.h"

class Instance
{
	public:
	Instance();
	~Instance();

	VkInstance handle() const { return _instance; }
	private:
	void printExtensionSupport();
	std::vector<const char*> getRequiredExtensions();

	bool checkValidationLayerSupport();
    VkInstance _instance;
};

#endif// INSTANCE_H
