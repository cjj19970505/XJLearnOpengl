#pragma once
#include <string>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include "Camera.h"
#include "Shader.h"
#include <vector>
using namespace std;
namespace XJ
{
	class XJLOSystem
	{
	public:
		unsigned int screenWidth;
		unsigned int screenHeight;
		Camera *currentCamera;
		Shader pointLightShader;
		//vector<PointLight> renderModels;
		XJLOSystem(int screenWidth, int screenHeight, Camera *camera) :screenWidth(screenWidth), screenHeight(screenHeight), currentCamera(camera),pointLightShader("PLVertShader.glsl", "PLFragShader.glsl"){}
		glm::mat4 getProjMat()
		{
			glm::mat4 projection;
			projection = glm::perspective(glm::radians(currentCamera->fov), (float)(screenWidth / screenHeight), 0.1f, 10.0f);
			return projection;
		}
	};
}