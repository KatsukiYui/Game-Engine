cmake_minimum_required(VERSION 3.0)
project(MYENGINE)

include_directories(
src
contrib # For glm.hpp
)

if(MSVC)
	include_directories(    
		contrib/SDL2/include/SDL2 # For SDL.h
		contrib/glew/include/GL # For glew.h 
	)  

	link_directories(    
		${CMAKE_SOURCE_DIR}/contrib/SDL2/lib/x64 
		${CMAKE_SOURCE_DIR}/contrib/glew/lib/Release/x64   
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
src/myengine/MyEngine.h
)

add_executable(game
src/game/main.cpp
)

target_link_libraries(game myengine)
target_link_libraries(myengine 
SDL2
glew32
)

if(WIN32)
    configure_file(contrib/SDL2/lib/x64/SDL2.dll SDL2.dll COPYONLY)
    configure_file(contrib/FBXSDK/lib/vs2017/x64/debug/libfbxsdk.dll libfbxsdk.dll COPYONLY)
    configure_file(contrib/glew/bin/Release/x64/glew32.dll glew32.dll COPYONLY)
endif()