#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID); // needs to be generated before the VBO
	//glBindVertexArray(ID);
}

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	// configure the vertex attribute so that openGL knows how to read the VBO
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, /*3 * sizeof(float)*/stride, offset);
	// enable the vertex attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(layout);


	VBO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}
