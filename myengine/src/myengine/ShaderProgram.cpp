#include "ShaderProgram.h"
#include <fstream>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Debugger.h"
#include "Exception.h"

namespace myengine
{
	void ShaderProgram::loadAsset(std::string _assetFolderPath, std::string _fileName)
	{
		// OpenGL doesn't provide any functions for loading shaders from file
		std::ifstream shaderProgramFileStream(_assetFolderPath + _fileName);
		char* combinedShaderText = NULL;

		if (shaderProgramFileStream.is_open())
		{
			// Find out how many characters are in the file
			shaderProgramFileStream.seekg(0, shaderProgramFileStream.end);
			int length = (int)shaderProgramFileStream.tellg();
			shaderProgramFileStream.seekg(0, shaderProgramFileStream.beg);

			// Create our buffer
			combinedShaderText = new char[length + 1];

			// Transfer data from file to buffer
			shaderProgramFileStream.read(combinedShaderText, length);

			// Check it reached the end of the file
			if (!shaderProgramFileStream.eof())
			{
				shaderProgramFileStream.close();
				Debugger::printWarning("could not read vertex shader from file: " + _fileName);
			}

			// Find out how many characters were actually read
			length = (int)shaderProgramFileStream.gcount();

			// Needs to be NULL-terminated
			combinedShaderText[length] = 0;

			shaderProgramFileStream.close();
		}
		else
		{
			Debugger::printWarning("could not open vertex shader from file: " + _fileName);
		}


		std::string vShaderText = "#version 430 core\n#define VERTEX_SHADER\n\n" + std::string(combinedShaderText);
		const char* vShaderTextChar = vShaderText.c_str();

		Debugger::printLog(vShaderText);

		std::string fShaderText = "#version 430 core\n#define FRAGMENT_SHADER\n\n" + std::string(combinedShaderText);
		const char* fShaderTextChar = fShaderText.c_str();

		Debugger::printLog(fShaderText);

		// The 'program' stores the shaders
		m_shaderProgram = glCreateProgram();

		// Create the vertex shader
		GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
		// Give GL the source for it
		glShaderSource(vShader, 1, &vShaderTextChar, NULL);
		// Delete buffer
		delete[] vShaderTextChar;
		// Compile the shader
		glCompileShader(vShader);
		// Check it compiled and give useful output if it didn't work!

		if (!checkShaderCompiled(vShader))
		{
			throw Exception("failed to compile vertex shader");
		}
		
		// This links the shader to the program
		glAttachShader(m_shaderProgram, vShader);

		// Same for the fragment shader
		GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fShader, 1, &fShaderTextChar, NULL);
		// Delete buffer
		delete[] fShaderTextChar;
		glCompileShader(fShader);

		if (!checkShaderCompiled(fShader))
		{
			throw Exception("failed to compile fragment shader");

		}

		glAttachShader(m_shaderProgram, fShader);

		// This makes sure the vertex and fragment shaders connect together
		glLinkProgram(m_shaderProgram);
		// Check this worked
		GLint linked;
		glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &linked);
		if (!linked)
		{
			GLsizei len;
			glGetProgramiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &len);

			GLchar* log = new GLchar[len + 1];
			glGetProgramInfoLog(m_shaderProgram, len, &len, log);
			throw Exception("Shader linking failed: " + std::string(log));
			delete[] log;

		}


		// We will define matrices which we will send to the shader
		// To do this we need to retrieve the locations of the shader's matrix uniform variables
		glUseProgram(m_shaderProgram);
		m_shaderModelMatLocation = glGetUniformLocation(m_shaderProgram, "modelMat");
		m_shaderViewMatLocation = glGetUniformLocation(m_shaderProgram, "viewMat");
		m_shaderProjMatLocation = glGetUniformLocation(m_shaderProgram, "projMat");

		m_shaderDiffuseColLocation = glGetUniformLocation(m_shaderProgram, "diffuseColour");
		m_shaderEmissiveColLocation = glGetUniformLocation(m_shaderProgram, "emissiveColour");
		m_shaderSpecularColLocation = glGetUniformLocation(m_shaderProgram, "specularColour");
		m_shaderWSLightPosLocation = glGetUniformLocation(m_shaderProgram, "worldSpaceLightPos");

		m_shaderTex1SamplerLocation = glGetUniformLocation(m_shaderProgram, "tex1");
	}

	int ShaderProgram::getShaderProgram()
	{
		return m_shaderProgram;
	}

	bool ShaderProgram::checkShaderCompiled(GLint _shader)
	{
		GLint compiled;
		glGetShaderiv(_shader, GL_COMPILE_STATUS, &compiled);
		if (!compiled)
		{
			GLsizei len;
			glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &len);

			// OpenGL will store an error message as a string that we can retrieve and print
			GLchar* log = new GLchar[len + 1];
			glGetShaderInfoLog(_shader, len, &len, log);
			throw Exception("Shader compilation failed: " + std::string(log));
			delete[] log;

			return false;
		}
		return true;

	}

	void ShaderProgram::setMatrices(glm::mat4 _modelMatrix, glm::mat4 _viewMatrix, glm::mat4 _projMatrix)
	{
		glUseProgram(m_shaderProgram);
		// Send matrices and uniforms
		glUniformMatrix4fv(m_shaderModelMatLocation, 1, GL_FALSE, glm::value_ptr(_modelMatrix));
		glUniformMatrix4fv(m_shaderViewMatLocation, 1, GL_FALSE, glm::value_ptr(_viewMatrix));
		glUniformMatrix4fv(m_shaderProjMatLocation, 1, GL_FALSE, glm::value_ptr(_projMatrix));
	}

	void ShaderProgram::apply()
	{
		/*
		glUseProgram(_shaderProgram);

		glUniform4fv(_shaderWSLightPosLocation, 1, glm::value_ptr(_lightPosition));

		glUniform3fv(_shaderEmissiveColLocation, 1, glm::value_ptr(_emissiveColour));
		glUniform3fv(_shaderDiffuseColLocation, 1, glm::value_ptr(_diffuseColour));
		glUniform3fv(_shaderSpecularColLocation, 1, glm::value_ptr(_specularColour));

		glActiveTexture(GL_TEXTURE0);
		glUniform1i(_shaderTex1SamplerLocation, 0);
		glBindTexture(GL_TEXTURE_2D, _texture1);
		*/
	}
}
