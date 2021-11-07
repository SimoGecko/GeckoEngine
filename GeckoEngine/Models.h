#pragma once

// vertices are in normalized viewport space [-1, 1]
//float sqrt3_3 = float(sqrt(3.f)) / 3.f;
//GLfloat vertices[] = // it's safer to use GLfloat rather than normal float to avoid sizes mismatch
//{
//	// COORDINATES                     COLORS
//	-0.5f, -0.5f * sqrt3_3,   0.0f,    0.8f, 0.3f, 0.02f,
//	 0.5f, -0.5f * sqrt3_3,   0.0f,    0.8f, 0.3f, 0.02f,
//	 0.0f,  0.5f * sqrt3_3*2, 0.0f,    1.0f, 0.6f, 0.32f,
//
//	-0.25f, 0.5f*sqrt3_3/2,   0.0f,    0.9f, 0.45f, 0.17f,
//	 0.25f, 0.5f*sqrt3_3/2,   0.0f,    0.9f, 0.45f, 0.17f,
//	 0.0f, -0.5f*sqrt3_3,     0.0f,    0.8f, 0.3f, 0.02f,
//};

Vertex pyramidVertices[] =
{ //             COORDINATES                /               NORMALS          /              COLORS               /          UVS   //
	Vertex{ glm::vec3(-0.5f, 0.0f,  0.5f),    glm::vec3( 0.0f, -1.0f, 0.0f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(0.0f, 0.0f)}, // Bottom side
	Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f),    glm::vec3( 0.0f, -1.0f, 0.0f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(0.0f, 5.0f)}, // Bottom side
	Vertex{ glm::vec3( 0.5f, 0.0f, -0.5f),    glm::vec3( 0.0f, -1.0f, 0.0f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(5.0f, 5.0f)}, // Bottom side
	Vertex{ glm::vec3( 0.5f, 0.0f,  0.5f),    glm::vec3( 0.0f, -1.0f, 0.0f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(5.0f, 0.0f)}, // Bottom side
	Vertex{ glm::vec3(-0.5f, 0.0f,  0.5f),    glm::vec3(-0.8f, 0.5f,  0.0f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(0.0f, 0.0f)}, // Left Side
	Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f),    glm::vec3(-0.8f, 0.5f,  0.0f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(5.0f, 0.0f)}, // Left Side
	Vertex{ glm::vec3( 0.0f, 0.8f,  0.0f),    glm::vec3(-0.8f, 0.5f,  0.0f),    glm::vec3(0.92f, 0.86f, 0.76f),    glm::vec2(2.5f, 5.0f)}, // Left Side
	Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f),    glm::vec3( 0.0f, 0.5f, -0.8f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(5.0f, 0.0f)}, // Non-facing side
	Vertex{ glm::vec3( 0.5f, 0.0f, -0.5f),    glm::vec3( 0.0f, 0.5f, -0.8f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(0.0f, 0.0f)}, // Non-facing side
	Vertex{ glm::vec3( 0.0f, 0.8f,  0.0f),    glm::vec3( 0.0f, 0.5f, -0.8f),    glm::vec3(0.92f, 0.86f, 0.76f),    glm::vec2(2.5f, 5.0f)}, // Non-facing side
	Vertex{ glm::vec3( 0.5f, 0.0f, -0.5f),    glm::vec3( 0.8f, 0.5f,  0.0f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(0.0f, 0.0f)}, // Right side
	Vertex{ glm::vec3( 0.5f, 0.0f,  0.5f),    glm::vec3( 0.8f, 0.5f,  0.0f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(5.0f, 0.0f)}, // Right side
	Vertex{ glm::vec3( 0.0f, 0.8f,  0.0f),    glm::vec3( 0.8f, 0.5f,  0.0f),    glm::vec3(0.92f, 0.86f, 0.76f),    glm::vec2(2.5f, 5.0f)}, // Right side
	Vertex{ glm::vec3( 0.5f, 0.0f,  0.5f),    glm::vec3( 0.0f, 0.5f,  0.8f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(5.0f, 0.0f)}, // Facing side
	Vertex{ glm::vec3(-0.5f, 0.0f,  0.5f),    glm::vec3( 0.0f, 0.5f,  0.8f),    glm::vec3(0.83f, 0.70f, 0.44f),    glm::vec2(0.0f, 0.0f)}, // Facing side
	Vertex{ glm::vec3( 0.0f, 0.8f,  0.0f),    glm::vec3( 0.0f, 0.5f,  0.8f),    glm::vec3(0.92f, 0.86f, 0.76f),    glm::vec2(2.5f, 5.0f)}, // Facing side
};

GLuint pyramidIndices[] =
{
	0, 1, 2, // Bottom side
	0, 2, 3, // Bottom side
	4, 6, 5, // Left side
	7, 9, 8, // Non-facing side
	10, 12, 11, // Right side
	13, 15, 14 // Facing side
};

Vertex planeVertices[] =
{ //             COORDINATES                /               NORMALS          /              COLORS               /          UVS   //
	Vertex{ glm::vec3(-1.0f, 0.0f,  1.0f),    glm::vec3(0.0f, 1.0f, 0.0f),    glm::vec3(0.0f, 0.0f, 0.0f),    glm::vec2(0.0f, 0.0f)},
	Vertex{ glm::vec3(-1.0f, 0.0f, -1.0f),    glm::vec3(0.0f, 1.0f, 0.0f),    glm::vec3(0.0f, 0.0f, 0.0f),    glm::vec2(0.0f, 1.0f)},
	Vertex{ glm::vec3( 1.0f, 0.0f, -1.0f),    glm::vec3(0.0f, 1.0f, 0.0f),    glm::vec3(0.0f, 0.0f, 0.0f),    glm::vec2(1.0f, 1.0f)},
	Vertex{ glm::vec3( 1.0f, 0.0f,  1.0f),    glm::vec3(0.0f, 1.0f, 0.0f),    glm::vec3(0.0f, 0.0f, 0.0f),    glm::vec2(1.0f, 0.0f)}
};

// Indices for vertices order
GLuint planeIndices[] =
{
	0, 1, 2,
	0, 2, 3
};

Vertex cubeVertices[] =
{ //             COORDINATES                
	Vertex{ glm::vec3(-0.1f, -0.1f,  0.1f)},
	Vertex{ glm::vec3(-0.1f, -0.1f, -0.1f)},
	Vertex{ glm::vec3( 0.1f, -0.1f, -0.1f)},
	Vertex{ glm::vec3( 0.1f, -0.1f,  0.1f)},
	Vertex{ glm::vec3(-0.1f,  0.1f,  0.1f)},
	Vertex{ glm::vec3(-0.1f,  0.1f, -0.1f)},
	Vertex{ glm::vec3( 0.1f,  0.1f, -0.1f)},
	Vertex{ glm::vec3( 0.1f,  0.1f,  0.1f)}
};

GLuint cubeIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};