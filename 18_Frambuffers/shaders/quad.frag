#version 440 core

out vec4 color;

in vec2 TexCoords;
uniform sampler2D screenTexture;

void main()
{
	color = texture(screenTexture, TexCoords);
	//color = vec4(1.0f);
}