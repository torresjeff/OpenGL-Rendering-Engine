#version 440 core

//All positions of this shader are in world coordinates

in vec3 Position;
in vec3 Normal;

out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor = vec3(1.0f);
uniform vec3 lightPosition;
uniform float ambientFactor;
uniform vec3 cameraPosition;

void main()
{
	float specularPower = 1.0f;
	vec3 norm = normalize(Normal);
	vec3 lightDirection = normalize(lightPosition - Position);
	vec3 directionToCamera = normalize(cameraPosition - Position);

	//Ambient light calculation
	vec3 ambient = ambientFactor * lightColor;
	//Diffuse light calculation
	float dir_dot_norm = max(dot(norm, lightDirection), 0.0);
	vec3 diffuse = dir_dot_norm * lightColor;
	//Specular light calculation
	vec3 reflectedLight = reflect(-lightDirection, norm); //Note that we negate the lightDir vector. The reflect function expects the first vector to
																	//point from the light source towards the fragment’s position
	vec3 directionToViewer = normalize(cameraPosition - Position);
	float shininess = pow(max(dot(reflectedLight, directionToViewer), 0.0), 256); //The exponent value is the shininess value of the highlight. 
																					//The lower the value the more it's spread across the surface,
																					//the higher the value the more it concentrates on a single point, effectively augmenting the shininess.
	if (gl_FragCoord.x >= 400) //We render to the right half of the screen using a specular power of 0.5. The left side is rendered using the specular power of 1.0. We use this to compare.
	{
		specularPower = 0.5f;
	}
	vec3 specular = shininess * specularPower * lightColor;

	//Final color
	color = vec4(objectColor * (ambient + diffuse + specular), 1.0f);
}