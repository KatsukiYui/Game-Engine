#include "Texture.h"
#include <SDL.h>
#include <fstream>

#include <glm/glm.hpp>
#include "glew.h"
#include "Exception.h"
#include "Debugger.h"

namespace myengine
{
	void Texture::loadAsset(std::string _assetFolderPath, std::string _fileName)
	{
		m_fileName = _fileName;

		// Load SDL surface
		SDL_Surface* image = SDL_LoadBMP((_assetFolderPath + _fileName).c_str());

		if (!image) // Check it worked
		{
			throw Exception("could not load BMP image: " + _fileName);
		}

		// Create OpenGL texture
		m_textureID = 0;
		glGenTextures(1, &m_textureID);


		glBindTexture(GL_TEXTURE_2D, m_textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// By default, OpenGL mag filter is linear
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		// By default, OpenGL min filter will use mipmaps
		// We therefore either need to tell it to use linear or generate a mipmap
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		// SDL loads images in BGR order
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_BGR, GL_UNSIGNED_BYTE, image->pixels);

		//glGenerateMipmap(GL_TEXTURE_2D);

		SDL_FreeSurface(image);

		//glBindTexture(GL_TEXTURE_2D, 0);
	}

	unsigned int Texture::getTextureID()
	{
		return m_textureID;
	}
}
