#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include <json/json.hpp>
#include "Mesh.h"

using json = nlohmann::json;

class Model
{
public:
	Model(const char* file);
	void Draw(Shader& shader, Camera& camera);

private:
	const char* file;
	std::vector<unsigned char> data;
	json JSON;

	std::vector<Mesh> meshes;
	std::vector<glm::vec3> translationsMeshes;
	std::vector<glm::quat> rotationsMeshes;
	std::vector<glm::vec3> scalesMeshes;
	std::vector<glm::mat4> matricesMeshes;

	// to avoid loading the same texture multiple times
	std::vector<std::string> loadedTexName;
	std::vector<Texture> loadedTex;

	// PURPOSE: Loads a single mesh by its name
	void loadMesh(unsigned int indexMesh);

	// PURPOSE: Traverses a node recursively, so it traverses all connected nodes
	void traverseNode(unsigned int nextNode, glm::mat4 matrix = glm::mat4(1.0f));

	// PURPOSE: Gets binary data from a bile
	std::vector<unsigned char> GetData();
	// PURPOSE: Interprets the binary data into floats, indices and textures
	std::vector<float> getFloats(json accessor);
	std::vector<GLuint> getIndices(json accessor);
	std::vector<Texture> getTextures();

	// PURPOSE: Assemble into vertices
	std::vector<Vertex> assembleVertices
	(
		std::vector<glm::vec3> positions,
		std::vector<glm::vec3> normals,
		std::vector<glm::vec2> texUVs
	);

	// PURPOSE: Helpers
	std::vector<glm::vec2> groupFLoatsVec2(std::vector<float>& floatVec);
	std::vector<glm::vec3> groupFLoatsVec3(std::vector<float>& floatVec);
	std::vector<glm::vec4> groupFLoatsVec4(std::vector<float>& floatVec);
};

#endif // !MODEL_CLASS_H