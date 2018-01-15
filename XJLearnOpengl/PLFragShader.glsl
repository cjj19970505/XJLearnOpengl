#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 vertexColor;
uniform sampler2D texture_diffuse1;
uniform sampler2D texture_diffuse2;
uniform sampler2D texture_diffuse3;
uniform vec4 lightColor;
void main()
{    
    //FragColor = texture(texture_diffuse3, TexCoords);
	FragColor = lightColor;
	
	//FragColor = vec4(TexCoords, 0, 1);
}