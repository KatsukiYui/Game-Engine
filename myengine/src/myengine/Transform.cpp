#include "Transform.h"

namespace myengine
{
	void Transform::update()
	{
		//fml
	}

	glm::vec3 Transform::multiplyByModelMatrix(glm::vec3 _point)
	{
		glm::mat4 translationMatrix = glm::translate(glm::identity<glm::mat4>(), Position);
		glm::mat4 rotationMatrix = glm::mat4_cast(Rotation);
		glm::mat4 scaleMatrix = glm::scale(glm::identity<glm::mat4>(), Scale);

		glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;

		glm::vec4 point(_point, 1); // adding a w to multiple by the model matrix
		point = modelMatrix * point;

		return glm::vec3(point.x, point.y, point.z);
	}
}