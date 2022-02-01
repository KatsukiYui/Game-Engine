#include <glm/glm.hpp>
#include <SDL.h>
#include "glew.h"
#include <string>

#include "Asset.h"

namespace myengine
{
	// For loading a mesh from OBJ file and keeping a reference for it
	class Mesh : public Asset
	{
	private:

		// OpenGL Vertex Array Object
		GLuint _VAO;

		// Number of vertices in the mesh
		unsigned int _numVertices;

	public:

		Mesh();
		~Mesh();

		// OBJ file must be triangulated
		void loadAsset(std::string _assetFolderPath, std::string _fileName) override;

		// Draws the mesh - must have shaders applied for this to display!
		void draw();
	};
}