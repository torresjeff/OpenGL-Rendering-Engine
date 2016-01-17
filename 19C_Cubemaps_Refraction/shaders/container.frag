#version 440 core

//All positions of this shader are in world coordinates

in vec3 Position;
in vec3 Normal;
in vec2 TexCoords;

out vec4 color;


uniform vec3 lightColor = vec3(1.0f);
uniform vec3 cameraPosition;

/* Material refractive properties:
Material	Refractive index
Air			1.00
Water		1.33
Ice			1.309
Glass		1.52
Diamond		2.42

We use these refractive indices to calculate the ratio between both materials the light passes through.
In our case, the light/view ray goes from air to glass (if we assume the container is made of glass) so the ratio becomes
1.00/1.52 = 0.658.
*/

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
	float ratio = 1.00/1.52;
	vec3 viewDirection = normalize(Position - cameraPosition);
	vec3 refractedVector = refract(viewDirection, normalize(Normal), ratio);
	//Final color
	color = texture(skybox, refractedVector);
}
