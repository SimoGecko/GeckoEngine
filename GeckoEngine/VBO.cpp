#include "VBO.h"

//VBO::VBO(GLfloat* vertices, GLsizeiptr size)
//{
//	glGenBuffers(1, &ID); // 1 = num3dObjects
//	glBindBuffer(GL_ARRAY_BUFFER, ID);
//	glBufferData(GL_ARRAY_BUFFER, /*sizeof(vertices)*/size, vertices, GL_STATIC_DRAW /*useOfdata*/); // store the vertices in the buffer
//}

VBO::VBO(std::vector<Vertex>& vertices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW /*useOfdata*/); // store the vertices in the buffer
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}
