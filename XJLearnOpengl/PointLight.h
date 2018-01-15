#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include "Model.h"
#include "XJBase.h"
#include "XJLOSystem.h"
namespace XJ
{
	class PointLight:XJBase
	{
	public:
		glm::vec3 position;
		glm::vec3 color;
		Model model;
		
		PointLight(XJLOSystem *xjSystem, glm::vec3 pos, glm::vec3 color):XJBase(xjSystem),model(Model(xjSystem, "cube.obj")), position(pos), color(color){}
	};
}


