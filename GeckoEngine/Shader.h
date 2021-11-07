#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H


#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

#include <glm/glm.hpp>

//const char* multilineString = R"<delimiter>(
//.....
//)<delimiter>";

std::string get_file_contents(const char* filename);

class Shader
{
public:
	GLuint ID; // shaderProgram
	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();
	void Delete();

	void SetUniform(const char* name, int val);
	void SetUniform(const char* name, float val);
	void SetUniform(const char* name, glm::vec2 vec);
	void SetUniform(const char* name, glm::vec3 vec);
	void SetUniform(const char* name, glm::vec4 vec);
	void SetUniform(const char* name, const glm::mat4& mat);

private:
	void CompileErrors(unsigned int shader, const char* type, const char* name = nullptr);

};

#endif // !SHADER_CLASS_H
