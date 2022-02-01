#include "Asset.h"
#include "glew.h"
#include <glm/glm.hpp>

namespace myengine
{
	class ShaderProgram : public Asset
	{
	private:
		// The OpenGL shader program handle
		int m_shaderProgram;

		// Locations of Uniforms in the vertex shader
		int m_shaderModelMatLocation;
		int m_shaderInvModelMatLocation;
		int m_shaderViewMatLocation;
		int m_shaderProjMatLocation;

		// Location of Uniforms in the fragment shader
		int m_shaderDiffuseColLocation, m_shaderEmissiveColLocation, m_shaderSpecularColLocation;
		int m_shaderWSLightPosLocation;
		int m_shaderTex1SamplerLocation;

		// Utility function
		bool checkShaderCompiled(GLint _shader);

	public:
		void loadAsset(std::string _assetFolderPath, std::string _fileName) override;
		void setMatrices(glm::mat4 _modelMatrix, glm::mat4 _viewMatrix, glm::mat4 _projMatrix);
		void apply();
		int getShaderProgram();
	};
}
