#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

void Camera::UpdateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	//view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
	view = glm::lookAt(Position, Position + Orientation, Up);

	const float fovRad = glm::radians(FOVdeg);
	const float aspect = (float)width / height;
	proj = glm::perspective(fovRad, aspect, nearPlane, farPlane);

	matrix = proj * view;
}

void Camera::Inputs(GLFWwindow * window)
{
	/*
	{
		// time
		float rotation = 0.0f;
		double prevTime = glfwGetTime();

		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1.f / 60)
		{
			rotation += 0.5f;
			prevTime = crntTime;
		}
		//model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
	}
	*/
	glm::vec3 OrientationPerp = glm::normalize(glm::cross(Orientation, Up));
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) Position += speed * Orientation;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) Position -= speed * Orientation;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) Position -= speed * OrientationPerp;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) Position += speed * OrientationPerp;

	if (glfwGetKey(window, GLFW_KEY_SPACE)        == GLFW_PRESS) Position += speed * Up;
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) Position -= speed * Up;
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)   == GLFW_PRESS) speed = 0.4f;
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) speed = 0.1f;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstCLick)
		{
			firstCLick = false;
			glfwSetCursorPos(window, width / 2, height / 2);
		}

		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));
		if (!((glm::angle(newOrientation, Up) <= glm::radians(5.0f)) or (glm::angle(newOrientation, -Up) <= glm::radians(5.0f))))
		{
			Orientation = newOrientation;
		}
		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

		glfwSetCursorPos(window, width / 2, height / 2);
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstCLick = true;
	}
}

const glm::mat4 Camera::Matrix() const
{
	return matrix;
}
