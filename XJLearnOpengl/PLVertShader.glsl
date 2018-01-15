#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec3 aBitangent;

out vec2 TexCoords;
out vec3 vertexColor;

struct App
{
	mat4 model;
	mat4 view;
	mat4 projection;
};
uniform App app;
uniform vec4 lightColor;
void main()
{
    gl_Position = app.projection * app.view * app.model * vec4(aPos, 1.0);
}