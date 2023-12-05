#include "vk_base.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

// Website try
bool checkValidationSupport(std::vector<const char*> validationLayers) {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
    for (const char* layername : validationLayers){
        bool layerFound = false;
        for (const VkLayerProperties& layerProperties : availableLayers){
            std::cout << layerProperties.layerName << std::endl;
            if (strcmp(layername, layerProperties.layerName) == 0){
                layerFound = true;
                break;
            }
        }
        if (!layerFound){
            return false;
        }
    }
    return true;
}


bool initVulkanInstance(VulkanContext* context) {
    
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan App";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
    createInfo.pApplicationInfo = &appInfo;
    //createInfo.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR; // MAC OS SPECIFIC
    createInfo.enabledLayerCount = 1; // MAC OS SPECIFIC
    //createInfo.ppEnabledLayerNames =  VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME ;


    const std::vector<const char*> validationLayers = {
                "VK_LAYER_KHRONOS_validation"
        };
        if (!checkValidationSupport(validationLayers)) {
            std::cout << "Error in validation layers initialization" << std::endl;
        } else {
            std::cout << "Validation Layers enabled" << std::endl;
        }


/*  Reddit Try
     const std::vector<const char*> validationLayers = {
                "VK_LAYER_LUNARG_standard_validation"
            };

    //Use the layers when creating the VkInstance
    createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
    createInfo.ppEnabledLayerNames = validationLayers.data();
    */

    VkResult result = vkCreateInstance(&createInfo, NULL, &context->instance);
    std::cout << result << std::endl;
    return true;
}

VulkanContext* initVulkan() {
    VulkanContext* context = new VulkanContext();
    if (initVulkanInstance(context) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
        
    }

    return context;
}
