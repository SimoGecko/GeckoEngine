#version 330 core

out vec4 FragColor;

in vec3 pos; // name needs to be the same
in vec3 normal;
in vec3 color;
in vec2 uv;

uniform sampler2D diffuse0;
uniform sampler2D specular0;

uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 camPos;

vec4 pointlight()
{
	vec3 lightVec = (lightPos - pos);
	float dist = length(lightVec);
	float a = 3.0f;
	float b = 0.7f;
	float inten = 1.0f / (a * dist * dist + b * dist + 1.0f);

	// ambient lighting
	float ambient = 0.2f;

	// diffuse lighting
	vec3 nnormal = normalize(normal);
	vec3 lightDir = normalize(lightVec);
	float diffuse = max(dot(nnormal, lightDir), 0.0f);

	// specular lighting
	float specularLight = 0.50f;
	vec3 viewDir = normalize(camPos - pos);
	vec3 reflectionDir = reflect(-lightDir, normal);
	float specAmount = pow(max(dot(viewDir, reflectionDir), 0.0f), 16);
	float specular = specAmount * specularLight;
	
	return (texture(diffuse0, uv) * (ambient + diffuse * inten) + texture(specular0, uv).r * specular * inten) * lightColor;
}

vec4 direclight()
{
	// ambient lighting
	float ambient = 0.2f;

	// diffuse lighting
	vec3 nnormal = normalize(normal);
	vec3 lightDir = normalize(vec3(1.0f, 1.0f, 0.0f));
	float diffuse = max(dot(nnormal, lightDir), 0.0f);

	// specular lighting
	float specularLight = 0.50f;
	vec3 viewDir = normalize(camPos - pos);
	vec3 reflectionDir = reflect(-lightDir, normal);
	float specAmount = pow(max(dot(viewDir, reflectionDir), 0.0f), 16);
	float specular = specAmount * specularLight;

	return (texture(diffuse0, uv) * (ambient + diffuse) + texture(specular0, uv).r * specular) * lightColor;
}

vec4 spotlight()
{
	float outerCone = 0.90f; // = cos(angle)
	float innerCone = 0.95f;

	// ambient lighting
	float ambient = 0.2f;

	// diffuse lighting
	vec3 nnormal = normalize(normal);
	vec3 lightDir = normalize(lightPos - pos);
	float diffuse = max(dot(nnormal, lightDir), 0.0f);

	// specular lighting
	float specularLight = 0.50f;
	vec3 viewDir = normalize(camPos - pos);
	vec3 reflectionDir = reflect(-lightDir, normal);
	float specAmount = pow(max(dot(viewDir, reflectionDir), 0.0f), 16);
	float specular = specAmount * specularLight;

	float angle = dot(vec3(0.0f, -1.0f, 0.0f), -lightDir);
	float inten = clamp((angle-outerCone)/(innerCone-outerCone), 0.0f, 1.0f);

	return (texture(diffuse0, uv) * (ambient + diffuse * inten) + texture(specular0, uv).r * specular * inten) * lightColor;
}

void main()
{
	FragColor = pointlight();
}