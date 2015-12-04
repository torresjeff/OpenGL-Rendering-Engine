#version 430 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 vertexColor;
out vec2 TexCoord; //Estos solo son los coordinates del texture, no el texture como tal

void main()
{
	gl_Position = vec4(position, 1.0f);
	vertexColor = color;
	TexCoord = vec2(texCoord.x, 1.0f - texCoord.y); //By default the image is flipped upside down. This is a hack to show the image the way it's supposed to be.
}