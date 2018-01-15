#pragma once
#include <string>
#include <glad\glad.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
using namespace std;
namespace XJ
{
	class Shader
	{
	public:
		unsigned int ID;
		Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
		Shader() :Shader("DefaultVertexShader.glsl", "DefaultFragmentShader.glsl") {};
		//使用/激活程序
		void use();
		//uniform工具函数
		void setBool(const std::string &name, bool value) const;
		void setInt(const std::string &name, int value) const;
		void setFloat(const std::string &name, float value) const;
		void setVector3(const std::string &name, glm::vec3 value) const;
		void setVector4(const std::string &name, glm::vec4 value) const;
		void setMatrix4(const std::string &name, glm::mat4 value) const;
		
	};
}


