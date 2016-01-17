#version 440 core

//All positions of this shader are in world coordinates

in vec3 Position;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;


uniform vec3 lightColor = vec3(1.0f);
uniform vec3 cameraPosition;

struct Material
{
	sampler2D diffuse;
	sampler2D specular; //The color impact a specular light has on the object. The color of the specular highlight.
	float shininess; //The scattering/radius of the specular highlight
};

uniform Material material;
uniform samplerCube skybox;

void main()
{
	vec3 viewDirection = normalize(Position - cameraPosition);
	vec3 reflectedVector = reflect(viewDirection, normalize(Normal));
	//Final color
	color = texture(skybox, reflectedVector);
}
