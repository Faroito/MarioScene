cmake_minimum_required(VERSION 2.8.4)
project(MarioScene)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)
if (APPLE)
    include_directories(/usr/local/include)
    find_library(GLFW3_LIBRARY glfw REQUIRED)
    find_library(GLEW_LIBRARY glew REQUIRED)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
    find_library(COREVID_LIBRARY CoreVideo REQUIRED)
endif (APPLE)

set(SOURCE_FILES
        source/ALight.cpp
        source/ALoader.cpp
        source/AObject.cpp
        source/App.cpp
        source/BulletBill.cpp
        source/Camera.cpp
        source/ConfigLoader.cpp
        source/Creature.cpp
        source/DirLight.cpp
        source/EasingFunctions.cpp
        source/Framebuffer.cpp
        source/Lamp.cpp
        source/Main.cpp
        source/MarioScene.cpp
        source/Mesh.cpp
        source/Misc.cpp
        source/Model.cpp
        source/MTLLoader.cpp
        source/Mushroom.cpp
        source/OBJLoader.cpp
        source/PointLight.cpp
        source/Shader.cpp
        source/ShaderLoader.cpp
        source/Window.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/stb_image/)

add_executable(MarioScene ${SOURCE_FILES})
target_link_libraries (MarioScene
    ${GLFW3_LIBRARY}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARY}
    ${COCOA_LIBRARY} ${COREVID_LIBRARY} ${IOKIT_LIBRARY})

if (UNIX)
    target_link_libraries (MarioScene
        ${OPENGL_LIBRARIES}
        ${GLFW3_LIBRARY}
        ${GLEW_LIBRARY}
        pthread)
endif (UNIX)
