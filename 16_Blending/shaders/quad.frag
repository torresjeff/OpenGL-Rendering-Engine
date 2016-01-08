#version 440 core

out vec4 color;

in vec2 TexCoords;
uniform sampler2D tex;

void main()
{
	color = texture(tex, TexCoords);
	//color = vec4(1.0f);
}