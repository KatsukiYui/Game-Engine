#include "Component.h"

namespace myengine
{
	class Mesh;
	class ShaderProgram;
	class Texture;

	/** An Entity component used to draw its mesh.
	* Stores the mesh, the shader program and the texture. 
	* @see Mesh.h */
	class MeshRenderer : public Component
	{
	protected:
		shared<Mesh> m_mesh;
		shared<ShaderProgram> m_shaderProgram;
		shared<Texture> m_texture;

	public:
		void render(glm::mat4 _viewMatrix, glm::mat4 _projMatrix) override;

		void setMesh(shared<Mesh> _mesh); /**< setter */
		void setShader(shared<ShaderProgram> _shaderProgram); /**< setter */
		void setTexture(shared<Texture> _texture); /**< setter */
	};
}