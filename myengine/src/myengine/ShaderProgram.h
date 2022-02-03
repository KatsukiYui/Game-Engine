#include "Asset.h"
#include "glew.h"
#include <glm/glm.hpp>

namespace myengine
{
	/** Reads in the vertex and fragment shader to make a shader program.
	* @see Asset.h	*/
	class ShaderProgram : public Asset
	{
	protected:
		/** The OpenGL shader program handle. */
		int m_shaderProgram;

		/** Locations of Uniforms in the vertex shader. */
		int m_shaderModelMatLocation;
		int m_shaderInvModelMatLocation; /**< @copydoc m_shaderModelMatLocation */
		int m_shaderViewMatLocation; /**< @copydoc m_shaderModelMatLocation */
		int m_shaderProjMatLocation; /**< @copydoc m_shaderModelMatLocation */

		/** Location of Uniforms in the fragment shader. */
		int m_shaderDiffuseColLocation;
		int m_shaderEmissiveColLocation; /**< @copydoc m_shaderDiffuseColLocation */
		int m_shaderSpecularColLocation; /**< @copydoc m_shaderDiffuseColLocation */
		int m_shaderWSLightPosLocation; /**< @copydoc m_shaderDiffuseColLocation */
		int m_shaderTex1SamplerLocation; /**< @copydoc m_shaderDiffuseColLocation */

		/** Utility function. */
		bool checkShaderCompiled(GLint _shader);

	public:
		/** Loads the shader file from the asset folder.
		* Overrides Asset::loadAsset() in parent class.
		* @see Asset.h	*/
		void loadAsset(std::string _assetFolderPath, std::string _fileName) override;

		/** Sets the matrix values in the shader program. */
		void setMatrices(glm::mat4 _modelMatrix, glm::mat4 _viewMatrix, glm::mat4 _projMatrix);
		void apply();

		/** Returns shader program handle/ID */
		int getShaderProgram();
	};
}
