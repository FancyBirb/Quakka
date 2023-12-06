cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
project(Quakka)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")


###make executable
set(SOURCE_FILES src/main.cpp src/vk_base/vk_device.cpp)
#find SDL2
#add_subdirectory(lib/SDL)
find_library(SDL2_LIBRARY NAME SDL2)
add_executable(Quakka ${SOURCE_FILES})
include_directories(Quakka PPRIVATE /opt/homebrew/include/SDL2)
target_link_libraries(Quakka PRIVATE /usr/local/lib/libSDL2.dylib)

#find Vulkan
find_package(Vulkan REQUIRED)

#vulkan executebl
#target_include_directories(Quakka PUBLIC lib/SDL/include)
target_link_libraries(Quakka PRIVATE Vulkan::Vulkan ${Vulkan_LIBRARIES})
target_link_libraries(Quakka PRIVATE ${Vulkan_LIBRARIES})