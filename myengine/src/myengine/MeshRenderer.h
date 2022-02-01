#include "Component.h"

namespace myengine
{
	class Mesh;
	class ShaderProgram;
	class Texture;
	class MeshRenderer : public Component
	{
	private:
		shared<Mesh> m_mesh;
		shared<ShaderProgram> m_shaderProgram;
		shared<Texture> m_texture;

	public:
		///////////insert complicated opengl shit here
		void render(glm::mat4 _viewMatrix, glm::mat4 _projMatrix) override;

		void setMesh(shared<Mesh> _mesh);
		void setShader(shared<ShaderProgram> _shaderProgram);
		void setTexture(shared<Texture> _texture);
	};
}