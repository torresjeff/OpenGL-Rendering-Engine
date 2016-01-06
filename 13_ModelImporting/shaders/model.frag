#version 440 core

out vec4 color;

/*in VS_OUT 
{
	vec3 position;
	vec3 normal;
	vec2 texCoord;
} IN;*/

/*struct Material
{
	// Diffuse maps
	sampler2D texture_diffuse1;
	//Specular maps
	sampler2D texture_specular1;
	//Normal maps
	sampler2D texture_normal1;
};*/

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;

//uniform Material material;

in vec3 Position;
in vec3 Normal;
in vec2 TexCoord;

void main()
{
	//color = texture(material.texture_diffuse1, IN.texCoord);
	//color = texture(texture_diffuse1, IN.texCoord);
	color = texture(texture_diffuse1, TexCoord);
	//color = vec4(Normal, 1.0f);
	//color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}