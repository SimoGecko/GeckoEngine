#version 330 core

layout (location = 0) in vec3 iPos;
layout (location = 1) in vec3 iNormal;
layout (location = 2) in vec3 iColor;
layout (location = 3) in vec2 iUv;

out vec3 pos;
out vec3 normal;
out vec3 color;
out vec2 uv;

uniform mat4 model;
uniform mat4 camMatrix; // proj * view

void main()
{
	pos = vec3(model * vec4(iPos, 1.0f));
	gl_Position = camMatrix * vec4(pos, 1.0);
	normal = iNormal;
	color = iColor;
	//uv = iUv;
	uv = mat2(0.0, -1.0, 1.0f, 0.0) * iUv; // rotatae by 90deg
}
