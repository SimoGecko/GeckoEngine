//#include "Mesh.h"
#include "Model.h"
//#include "Models.h"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#define NUMELEMS(x) (sizeof(x)/sizeof(x[0]))

const unsigned int windowWidth  = 1920;
const unsigned int windowHeight = 1080;


int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW the version of OpenGL we're using (OpenGL 3.3)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we are using the CORE profile, meaning only the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFW window
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Gecko Engine", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window to the current context
	// the context is an object that holds the whole of openGL. we now introduce the new window
	glfwMakeContextCurrent(window);
	//glfwSwapInterval(1); // Enable vsync

	// Load GLAD so it configures OpenGL
	gladLoadGL(); // load the needed config for OpenGL
	glViewport(0, 0, windowWidth, windowHeight); // tell openGL which part of the window we want to render

	// IMGUI
	//{
		const char* glsl_version = "#version 330";

		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();

		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init(glsl_version);
		//ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
	//}

	//Texture textures[]
	//{
	//	Texture("../Assets/Images/planks.png", "diffuse",  0/*, GL_RGBA, GL_UNSIGNED_BYTE*/),
	//	Texture("../Assets/Images/planks.png", "specular", 1/*, GL_RED,  GL_UNSIGNED_BYTE*/),
	//};
	Shader shaderProgram("default.vert", "default.frag");

	//std::vector<Vertex> vert(planeVertices, planeVertices + NUMELEMS(planeVertices));
	//std::vector<GLuint> ind(planeIndices, planeIndices + NUMELEMS(planeIndices));
	//std::vector<Texture> tex(textures, textures + NUMELEMS(textures));
	//Mesh floorMesh(vert, ind, tex);

	//shaderProgram.SetUniform("tex0", 0);
	//shaderProgram.SetUniform("tex1", 1);
	//planksTex.texUnit(shaderProgram, "tex0", 0);
	//planksSpec.texUnit(shaderProgram, "tex1", 1);

	{
		// sending stuff between CPU <--> GPU is pretty slow, so you want to send stuff in big batches (buffers)
		// binding = we make the object the current object so we can modify it
		// all openGL objects are referenced by numbers
		// Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we ...
		// the ordering of the functions is very important
	}

	// pyramid


	// light cube

	//std::vector<Vertex> lightVerts(cubeVertices, cubeVertices + NUMELEMS(cubeVertices));
	//std::vector<GLuint> lightInds(cubeIndices, cubeIndices + NUMELEMS(cubeIndices));
	//Mesh lightMesh(lightVerts, lightInds, tex);


	//Shader lightShader("light.vert", "light.frag");
	//VAO lightVAO;
	//lightVAO.Bind();
	//VBO lightVBO(cubeVertices, sizeof(cubeVertices));
	//EBO lightEBO(cubeIndices, sizeof(cubeIndices));
	//lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	//lightVAO.Unbind();
	//lightVBO.Unbind();
	//lightEBO.Unbind();


	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	//glm::vec3 pyramidPos = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::mat4 pyramidModel = glm::mat4(1.0f);
	//pyramidModel = glm::translate(pyramidModel, pyramidPos);

	//lightShader.Activate();
	//lightShader.SetUniform("model", lightModel);
	//lightShader.SetUniform("lightColor", lightColor);
	//lightShader.SetUniform("scale", 0.2f);

	shaderProgram.Activate();
	//shaderProgram.SetUniform("model", pyramidModel);
	shaderProgram.SetUniform("lightColor", lightColor);
	shaderProgram.SetUniform("lightPos", lightPos);

	// TEXTURES
	//Texture bricksTex("../Assets/Images/brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	//bricksTex.texUnit(shaderProgram, "tex0", 0);



	// Enables the depth buffer
	glEnable(GL_DEPTH_TEST);

	// Creates the camera object
	Camera camera(windowWidth, windowHeight, glm::vec3(0.0f, 1.0f, 2.0f));

	Model model("../Assets/Models/map/scene.gltf");
	bool show_demo_window = true;

	// main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f); // blue
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// camera
		camera.Inputs(window);
		camera.UpdateMatrix(45.0f, 0.1f, 100.0f);

		/*
		// Tell OpenGl which Shader Program we want to use
		shaderProgram.Activate();
		shaderProgram.SetUniform("camPos", camera.Position);
		shaderProgram.SetUniform("camMatrix", camera.Matrix());
		planksTex.Bind();
		planksSpec.Bind(); // don't forget
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, NUMELEMS(pyramidIndices), GL_UNSIGNED_INT, 0);

		lightShader.Activate();
		shaderProgram.SetUniform("camMatrix", camera.Matrix());
		lightVAO.Bind();
		glDrawElements(GL_TRIANGLES, NUMELEMS(cubeIndices), GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		*/

		model.Draw(shaderProgram, camera);


		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();


		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


		//floorMesh.Draw(shaderProgram, camera);
		//lightMesh.Draw(lightShader, camera);

		// swap back buffer and front buffer
		glfwSwapBuffers(window);

		// poll events
		glfwPollEvents();
	}

	// delete all the objects we've created
	shaderProgram.Delete();
	//lightShader.Delete();

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	// Delete the window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}