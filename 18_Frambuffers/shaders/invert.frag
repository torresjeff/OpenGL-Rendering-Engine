#version 440 core

out vec4 color;

in vec2 TexCoords;
uniform sampler2D screenTexture;

void main()
{
	color = vec4(vec3(1.0f - texture(screenTexture, TexCoords)), 1.0f);
}