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
struct DirectionalLight
{
	vec3 direction;

	vec3 ambient; //Contains the ambient strength for each channel, usually same value for all channels. eg. (0.1f, 0.1f, 0.1f).
				//The ambient color is usually low so it doesn't have much impact on an object
	vec3 diffuse; //The color of the light itself, has the greatest impact on the object. Often a white color.
	vec3 specular; //Contains a specular factor. A specular factor of (1.0f, 1.0f, 1.0f) means the light is shining at full intensity.
};

//To implement attenuation we use the formula: 
// F_{att} = I / (Kc + Kl * d + Kq * d^{2}). Where I = the intensity of the light, Kc is a constant (almost always one so we don't divide by 0),
// and Kl and Kq vary depending on the distance we want the light to cover. See more: http://www.ogre3d.org/tikiwiki/tiki-index.php?page=-Point+Light+Attenuation
struct PointLight
{
	vec3 position; //With a point light we DO care about it's position, we can then calculate the distance from the fragment to the position to evaluate the attenuation at a specific point.

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float intensity;
	float Kc; // Constant
	float Kl; // Linear
	float Kq; // Quadratic
};

struct SpotLight
{
	vec3 position;
	vec3 direction;
	float innerAngle;
	float outerAngle;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

uniform Material material;
uniform DirectionalLight directionalLight;
uniform PointLight pointLight;
uniform SpotLight spotLight;

void main()
{
	//DIRECTIONAL LIGHT CALCULATIONS
	/*
	//Ambient light
	vec3 diffuseSample = vec3(texture(material.diffuse, TexCoords));
	vec3 ambient = directionalLight.ambient * diffuseSample;
	//Diffuse light
	vec3 lightDirection = normalize(-directionalLight.direction); //We negate it because the incoming direction is FROM the light source TO the object. But our calculations are done the opposite.
	vec3 norm = normalize(Normal);
	float diffuseFactor = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = directionalLight.diffuse * diffuseFactor * diffuseSample;
	//Specular light
	vec3 reflectedLight = reflect(-lightDirection, norm);
	vec3 directionToViewer = normalize(cameraPosition - Position);
	float shininess = pow(max(dot(reflectedLight, directionToViewer), 0.0), material.shininess);
	vec3 specular = directionalLight.specular * shininess * vec3(texture(material.specular, TexCoords));
	*/

	//POINT LIGHT CALCULATIONS
	/*
	//Ambient light
	vec3 diffuseSample = vec3(texture(material.diffuse, TexCoords));
	vec3 ambient = pointLight.ambient * diffuseSample;
	//Diffuse light
	vec3 lightDirection = normalize(pointLight.position - Position); //We negate it because the incoming direction is FROM the light source TO the object. But our calculations are done the opposite.
	vec3 norm = normalize(Normal);
	float diffuseFactor = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = pointLight.diffuse * diffuseFactor * diffuseSample;
	//Specular light
	vec3 reflectedLight = reflect(-lightDirection, norm);
	vec3 directionToViewer = normalize(cameraPosition - Position);
	float shininess = pow(max(dot(reflectedLight, directionToViewer), 0.0), material.shininess);
	vec3 specular = pointLight.specular * shininess * vec3(texture(material.specular, TexCoords));

	float distanceMagnitude = length(Position - pointLight.position);
	float attenuation = pointLight.intensity / (pointLight.Kc + pointLight.Kl * distanceMagnitude + pointLight.Kq * distanceMagnitude * distanceMagnitude);

	//ambient *= attenuation; //We can ignore the ambient so the ambient lighting doesn't decrease over distance, but if we were to use more than 1 light source all the ambient components will
 							// start to stack up 
	diffuse *= attenuation;
	specular *= attenuation;
	*/

	//SPOT LIGHT CALCULATIONS
	float cosInnerAngle = cos(spotLight.innerAngle);
	float cosOuterAngle = cos(spotLight.outerAngle);
	vec3 lightDirection = normalize(spotLight.position - Position); //We negate it because the incoming direction is FROM the light source TO the object. But our calculations are done the opposite.
	float lightDirDOTspotDir = dot(lightDirection, normalize(-spotLight.direction));

	vec3 diffuseSample = vec3(texture(material.diffuse, TexCoords));

	//Ambient light
	vec3 ambient = spotLight.ambient * diffuseSample;
	//Diffuse light
	vec3 norm = normalize(Normal);
	float diffuseFactor = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = spotLight.diffuse * diffuseFactor * diffuseSample;
	//Specular light
	vec3 reflectedLight = reflect(-lightDirection, norm);
	vec3 directionToViewer = normalize(cameraPosition - Position);
	float shininess = pow(max(dot(reflectedLight, directionToViewer), 0.0), material.shininess);
	vec3 specular = spotLight.specular * shininess * vec3(texture(material.specular, TexCoords));

	float intensity = clamp((lightDirDOTspotDir - cosOuterAngle) / (cosInnerAngle - cosOuterAngle), 0.0, 1.0); //Interpolate between inner and outer cone

	diffuse *= intensity;
	specular *= intensity;


	//Final color
	color = vec4(ambient + diffuse + specular, 1.0f);
}