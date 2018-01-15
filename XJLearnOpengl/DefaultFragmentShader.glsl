#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 worldPos;
in vec3 worldNormal;
uniform sampler2D texture_diffuse1;
uniform sampler2D texture_diffuse2;
uniform sampler2D texture_diffuse3;
struct App
{
	vec3 lightPos[3];
	vec4 lightColor[3];
	
	mat4 model;
	mat4 view;
	mat4 projection;
};
uniform App app;
float LinearizeDepth(float depth, float near, float far) 
{
    float z = depth * 2.0 - 1.0; // back to NDC 
    return (2.0 * near * far) / (far + near - z * (far - near));    
}
void main()
{
    vec3 normalizedWorldNormal = normalize(worldNormal);
	vec3 albedo = texture(texture_diffuse3, TexCoords).xyz;
	vec3 worldLightDir = normalize(app.lightPos[0]-worldPos);
	
	vec3 diffuse = max(0, dot(worldLightDir,normalizedWorldNormal))*app.lightColor[0].xyz*albedo;
	//FragColor = abs(vec4(dot(worldLightDir,normalizedWorldNormal),dot(worldLightDir,normalizedWorldNormal),dot(worldLightDir,normalizedWorldNormal), 1));
	FragColor = vec4(diffuse, 1);
	//FragColor = vec4(vec3(LinearizeDepth(gl_FragCoord.z, 0.1f, 3.0f)), 1.0);
	
	//FragColor = vec4(gl_FragCoord.xy,0, 1);
	//FragColor = vec4(TexCoords, 0, 1);
}
