#ifndef EBO_H
#define EBO_H

#include <vector>
#include <glad/glad.h>

class EBO // elements buffer object
{
public:
	GLuint ID;
	//EBO(GLuint* indices, GLsizeiptr size);
	EBO(std::vector<GLuint>& indices);

	void Bind();
	void Unbind();
	void Delete();
};


#endif // !EBO_H
