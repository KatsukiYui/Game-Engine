cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
src
contrib # For glm.hpp
)

if(MSVC)
	include_directories(    
		contrib/SDL2/include # For SDL.h
		contrib/glew/include # For glew.h 
	)  

	link_directories(    
		${CMAKE_SOURCE_DIR}/contrib/SDL2/lib  
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
)

add_executable(game
 src/game/main.cpp
)

target_link_libraries(game myengine)
target_link_libraries(myengine SDL2)