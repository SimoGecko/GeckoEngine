#include "EBO.h"

//EBO::EBO(GLuint* indices, GLsizeiptr size)
//{
//	glGenBuffers(1, &ID);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, /*sizeof(indices)*/size, indices, GL_STATIC_DRAW); // store the indices in the buffer
//}

EBO::EBO(std::vector<GLuint>& indices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW); // store the indices in the buffer
}

void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
	glDeleteBuffers(1, &ID);
}
