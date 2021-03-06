// XJLearnOpengl.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <glad\glad.h>
#include <GLFW\glfw3.h>


// GLM
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>


#include <iostream>
#include "XJLOSystem.h"

#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "Mesh.h"
#include "PointLight.h"
using namespace XJ;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
void processInput(GLFWwindow *window);
vector<PointLight*> lightSources;
vector<Model*> renderModels;
Camera camera(glm::vec3(0, 0, 3), glm::vec3(0, -90, 0));
int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//stbi_set_flip_vertically_on_load(true);
	unsigned int screenWidth = 1280;
	unsigned int screenHeight = 720;
	
	GLFWwindow *window = glfwCreateWindow(screenWidth, screenHeight, "LearnOPENGL", nullptr, nullptr);

	if (window == nullptr)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	XJLOSystem xjloSystem(screenWidth, screenHeight, &camera);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, xjloSystem.screenWidth, xjloSystem.screenHeight);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	//====TestData===
	Shader shader("DefaultVertexShader.glsl", "DefaultFragmentShader.glsl");
	Model nanoModel(&xjloSystem, "./nanosuit.obj");
	nanoModel.scale = glm::vec3(0.1, 0.1, 0.1);
	Vertex v1(1.0f, 0.0f, 0.0f);
	Vertex v2(0.0f, -1.0f, 0.0f);
	Vertex v3(0.0f, 0.0f, 1.0f);
	Vertex v4(0.0f, 1.0f, 0.0f);
	vector<Vertex> centerVertex{ v1, v2, v3, v4 };
	vector<unsigned int> centerIndices = {
		1, 2, 3, 0, 3, 2, 0, 1, 2, 1, 3, 0
	};
	vector<Texture> centerTexture;
	Mesh centerMesh(&xjloSystem, centerVertex, centerIndices, centerTexture);
	
	//===============
	//glDepthMask(GL_FALSE);
	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.5f, 0.5f, 0.05f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		nanoModel.draw(shader);
		
		for (auto i = renderModels.begin(); i != renderModels.end(); i++)
		{
			(*i)->draw(shader);
		}
		//centerMesh.draw(shader, nanoModel.getModelMatrix());
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	camera.mouse_callback(window, xpos, ypos);
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

}
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	camera.processInput(window);
}
