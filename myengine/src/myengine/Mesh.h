#include <glm/glm.hpp>
#include <SDL.h>
#include "glew.h"
#include <string>

#include "Asset.h"

namespace myengine
{
	/** For loading a mesh from OBJ file and keeping a reference for it.
	* @see Asset.h	*/
	class Mesh : public Asset
	{
	protected:

		/**  OpenGL Vertex Array Object. */
		GLuint m_VAO;

		/** Number of vertices in the mesh. */
		unsigned int m_numVertices;

	public:

		Mesh();
		~Mesh();

		/** Loads the triangulated mesh from the asset folder.
		* Overrides Asset::loadAsset() in parent class.
		* @see Asset.h	*/
		void loadAsset(std::string _assetFolderPath, std::string _fileName) override; 

		/** Draws the mesh. Must have shaders applied for this to display! */
		void draw();
	};
}