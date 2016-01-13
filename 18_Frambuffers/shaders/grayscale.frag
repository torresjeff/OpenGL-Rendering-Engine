#version 440 core

out vec4 color;

in vec2 TexCoords;
uniform sampler2D screenTexture;

void main()
{
	color = texture(screenTexture, TexCoords);
	//The human eye tends to be more sensitive to green colors and the least to blue, so to get the most physically accurate results we'll need to use weighted channels.
	//Note we could also use average = (color.r + color.b + color.g) / 3.0f
	float average = 0.2126 * color.r + 0.7152 * color.g + 0.0722 * color.b;

	color = vec4(average, average, average, 1.0f);
}