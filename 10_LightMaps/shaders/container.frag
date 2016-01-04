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

//Light sources also have different intensities for their ambient, diffuse and specular
struct Light
{
	vec3 position;

	vec3 ambient; //Contains the ambient strength for each channel, usually same value for all channels. eg. (0.1f, 0.1f, 0.1f).
				//The ambient color is usually low so it doesn't have much impact on an object
	vec3 diffuse; //The color of the light itself, has the greatest impact on the object. Often a white color.
	vec3 specular; //Contains a specular factor. A specular factor of (1.0f, 1.0f, 1.0f) means the light is shining at full intensity.
};

uniform Material material;
uniform Light light;

void main()
{
	//Ambient light
	vec3 diffuseSample = vec3(texture(material.diffuse, TexCoords));
	vec3 ambient = light.ambient * diffuseSample;
	//Diffuse light
	vec3 norm = normalize(Normal);
	vec3 lightDirection = normalize(light.position - Position);
	float diffuseFactor = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = light.diffuse * diffuseFactor * diffuseSample;
	//Specular light
	float specularPower = 0.5f;
	vec3 reflectedLight = reflect(-lightDirection, norm); //Note that we negate the lightDir vector. The reflect function expects the first vector to
																	//point from the light source towards the fragment’s position
	vec3 directionToViewer = normalize(cameraPosition - Position);
	float shininess = pow(max(dot(reflectedLight, directionToViewer), 0.0), material.shininess); //The exponent value is the shininess value of the highlight. 
																					//The lower the value the more it's spread across the surface,
																					//the higher the value the more it concentrates on a single point, effectively augmenting the shininess.
	vec3 specular = light.specular * shininess * vec3(texture(material.specular, TexCoords)); //We could remove the specularPower variable, but all 

	//Final color
	color = vec4(ambient + diffuse + specular, 1.0f);
}