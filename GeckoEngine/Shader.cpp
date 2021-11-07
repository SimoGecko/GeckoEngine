#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>

std::string get_file_contents(const char * filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return contents;
	}
	throw errno;
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode   = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertexSource   = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// we need to crate shader objects
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, nullptr); // 1 = screenForShader
	glCompileShader(vertexShader); // we need to compile the shader
	CompileErrors(vertexShader, "VERTEX", vertexFile);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
	glCompileShader(fragmentShader);
	CompileErrors(fragmentShader, "FRAGMENT", fragmentFile);

	// we need to wrap them up in a shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	CompileErrors(fragmentShader, "PROGRAM");

	glDeleteShader(vertexShader); // we can delete them because they are already in the program
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}

void Shader::SetUniform(const char* name, int val)
{
	GLuint uniformLocation = glGetUniformLocation(ID, name);
	glUniform1i(uniformLocation, val);
}

void Shader::SetUniform(const char* name, float val)
{
	GLuint uniformLocation = glGetUniformLocation(ID, name);
	glUniform1f(uniformLocation, val);
}

void Shader::SetUniform(const char* name, glm::vec2 vec)
{
	GLuint uniformLocation = glGetUniformLocation(ID, name);
	glUniform2f(uniformLocation, vec.x, vec.y);
}

void Shader::SetUniform(const char* name, glm::vec3 vec)
{
	GLuint uniformLocation = glGetUniformLocation(ID, name);
	glUniform3f(uniformLocation, vec.x, vec.y, vec.z);
}

void Shader::SetUniform(const char* name, glm::vec4 vec)
{
	GLuint uniformLocation = glGetUniformLocation(ID, name);
	glUniform4f(uniformLocation, vec.x, vec.y, vec.z, vec.w);
}

void Shader::SetUniform(const char* name, const glm::mat4& mat)
{
	GLuint uniformLocation = glGetUniformLocation(ID, name);
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::CompileErrors(unsigned int shader, const char * type, const char* name)
{
	GLint hasCompiled;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for: " << type << " (" << (name ? name : "") << ")\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for: " << type << " (" << (name ? name : "") << ")\n" << infoLog << std::endl;
		}
	}
}
