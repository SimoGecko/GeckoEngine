#ifndef VBO_H
#define VBO_H

#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>


struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 uv;
};

class VBO // Vertex Buffer Object
{
public:
	GLuint ID;
	//VBO(GLfloat* vertices, GLsizeiptr size);
	VBO(std::vector<Vertex>& vertices);

	void Bind();
	void Unbind();
	void Delete();
};


#endif // !VBO_H
