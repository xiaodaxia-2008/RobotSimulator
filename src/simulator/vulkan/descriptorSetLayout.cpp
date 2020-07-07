//--------------------------------------------------
// Robot Simulator
// descriptorSetLayout.cpp
// Date: 06/07/2020
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "descriptorSetLayout.h"

DescriptorSetLayout::DescriptorSetLayout(Device* device)
{
	_device = device;

	VkDescriptorSetLayoutBinding uboLayoutBinding{};
    uboLayoutBinding.binding = 0;
    uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    uboLayoutBinding.descriptorCount = 1;
	uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
	uboLayoutBinding.pImmutableSamplers = nullptr; // Optional

	VkDescriptorSetLayoutCreateInfo layoutInfo{};
	layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
	layoutInfo.bindingCount = 1;
	layoutInfo.pBindings = &uboLayoutBinding;


	if(vkCreateDescriptorSetLayout(_device->handle(), &layoutInfo, nullptr, &_descriptorSetLayout) != VK_SUCCESS)
	{
		std::cout << BOLDRED << "[DescriptorSetLayout]" << RESET << RED << " Failed to create descriptor set layout!" << RESET << std::endl;
		exit(1);
	}
}

DescriptorSetLayout::~DescriptorSetLayout()
{
	if(_descriptorSetLayout != nullptr)
	{
		vkDestroyDescriptorSetLayout(_device->handle(), _descriptorSetLayout, nullptr);
		_descriptorSetLayout = nullptr;

	}
}