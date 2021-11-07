#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	VAO.Bind();
	// Generate the Vertex Buffer Object and links it to vertices
	//VBO VBO1(pyramidVertices, sizeof(pyramidVertices));
	VBO VBO(vertices);
	// Generate the Element Buffer Object and links it ot the indices
	EBO EBO(indices);

	// Links VBO attributes such as coordinates and colors to the VAO
	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)(0)); // position
	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float))); // normal
	VAO.LinkAttrib(VBO, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float))); // color
	VAO.LinkAttrib(VBO, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float))); // uv
	VAO.Unbind();
	VBO.Unbind();
	EBO.Unbind();
}

void Mesh::Draw(Shader& shader, Camera& camera, glm::vec3 translation, glm::quat rotation, glm::vec3 scale)
{
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 rot   = glm::mat4(1.0f);
	glm::mat4 sca = glm::mat4(1.0f);

	trans = glm::translate(trans, translation);
	rot = glm::mat4_cast(rotation);
	sca = glm::scale(sca, scale);

	glm::mat4 matrix = trans * -rot * sca; // -rot because "it works" (maybe cw-ccw)

	Draw(shader, camera, matrix);
}
void Mesh::Draw(Shader& shader, Camera& camera, glm::mat4 matrix)
{
	shader.Activate();
	VAO.Bind();

	unsigned int numDiffuse = 0;
	unsigned int numSpecular = 0;
	for (unsigned int i = 0; i < textures.size(); ++i)
	{
		std::string num;
		std::string type = textures[i].type;
		if (type == "diffuse")
		{
			num = std::to_string(numDiffuse++);
		}
		else if (type == "specular")
		{
			num = std::to_string(numSpecular++);
		}
		else
		{
			std::cout << "invalid texture type: " << type << std::endl;
		}

		//textures[i].texUnit(shader, )

		shader.SetUniform((type + num).c_str(), (int)i); // HACKY
		textures[i].Bind();

		shader.SetUniform("camPos", camera.Position);
		shader.SetUniform("camMatrix", camera.Matrix());
		shader.SetUniform("model", matrix);

		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	}
}
