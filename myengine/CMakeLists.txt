cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
src
contrib # For glm.hpp
)

add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>") #Debug stuff

if(MSVC)
	include_directories(    
		contrib/SDL2/include/SDL2 # For SDL.h
		contrib/glew/include/GL # For glew.h
		contrib/OpenAL/include #For OpenAL.h
	)  

	link_directories(    
		${CMAKE_SOURCE_DIR}/contrib/SDL2/lib/x64 
		${CMAKE_SOURCE_DIR}/contrib/glew/lib/Release/x64
		${CMAKE_SOURCE_DIR}/contrib/OpenAL/libs/Win64   
	)
else()  
	# Linux, Emscripten, macOS equivalents
endif()

# Avoid the weird SDL2main hack
if(MSVC)  
	add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(myengine
src/myengine/Core.cpp
src/myengine/Core.h

src/myengine/Entity.cpp
src/myengine/Entity.h

src/myengine/Component.cpp
src/myengine/Component.h

src/myengine/TriangleRenderer.cpp
src/myengine/TriangleRenderer.h

src/myengine/Transform.cpp
src/myengine/Transform.h

src/myengine/Exception.cpp
src/myengine/Exception.h

src/myengine/Debugger.cpp
src/myengine/Debugger.h

src/myengine/Timer.cpp
src/myengine/Timer.h

src/myengine/Mesh.cpp
src/myengine/Mesh.h

src/myengine/ShaderProgram.cpp
src/myengine/ShaderProgram.h

src/myengine/Texture.cpp
src/myengine/Texture.h

src/myengine/MeshRenderer.cpp
src/myengine/MeshRenderer.h

src/myengine/Asset.cpp
src/myengine/Asset.h

src/myengine/Camera.cpp
src/myengine/Camera.h

src/myengine/Audio.cpp
src/myengine/Audio.h

src/myengine/AudioSource.cpp
src/myengine/AudioSource.h

src/myengine/AudioListener.cpp
src/myengine/AudioListener.h

src/myengine/InputManager.cpp
src/myengine/InputManager.h

src/myengine/AssetManager.cpp
src/myengine/AssetManager.h

src/myengine/MemoryDefines.h
src/myengine/InputDefines.h

src/myengine/MyEngine.h
)

add_executable(game
src/game/main.cpp
)

target_link_libraries(game myengine)
target_link_libraries(myengine 
SDL2
glew32
openGL32
OpenAL32
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT game)

if(WIN32)
	configure_file(contrib/SDL2/lib/x64/SDL2.dll SDL2.dll COPYONLY)
	configure_file(contrib/glew/bin/Release/x64/glew32.dll glew32.dll COPYONLY)
	configure_file(contrib/OpenAL/OpenAL32.dll OpenAL32.dll COPYONLY)
endif()