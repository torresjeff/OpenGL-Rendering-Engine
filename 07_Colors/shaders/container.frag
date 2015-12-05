#version 440 core

in vec2 texCoords;

out vec4 color;

uniform sampler2D ourTexture;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
	//color = texture(ourTexture, texCoords);
	color = vec4(lightColor * objectColor, 1.0f);
}