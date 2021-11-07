#version 330 core

out vec4 FragColor;

uniform vec4 lightColor;

void main()
{
	FragColor = lightColor; //vec4(1.0f, 1.0f, 1.0f, 1.0f);
}