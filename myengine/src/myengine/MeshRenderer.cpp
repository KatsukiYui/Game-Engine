#include "MeshRenderer.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "Transform.h"

namespace myengine
{
	void MeshRenderer::render(glm::mat4 _viewMatrix, glm::mat4 _projMatrix)
	{

		if (m_mesh != NULL)
		{
			if (m_shaderProgram != NULL)
			{
				shared<Transform> transform = m_transform.lock();
				// Give all the matrices to the material
				// This makes sure they are sent to the shader
				m_shaderProgram->setMatrices(transform->getModelMatrix(), _viewMatrix, _projMatrix);
				// This activates the shader
				m_shaderProgram->apply();
			}

			// Sends the mesh data down the pipeline
			m_mesh->draw();
		}
	}

	void MeshRenderer::setMesh(shared<Mesh> _mesh)
	{
		m_mesh = _mesh;
	}

	void MeshRenderer::setShader(shared<ShaderProgram> _shaderProgram)
	{
		m_shaderProgram = _shaderProgram;
	}

	void MeshRenderer::setTexture(shared<Texture> _texture)
	{
		m_texture = _texture;
	}
}
