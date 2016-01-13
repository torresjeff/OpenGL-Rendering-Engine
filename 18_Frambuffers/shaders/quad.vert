#version 440 core

layout (location = 0) in vec2 position; //Use 2D coordinates because we are going to supply the vertex positions already in Normalized Device Coordinates that span the whole screen.
layout (location = 1) in vec2 texCoords;

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
	//TexCoords = vec2(texCoords.x, 1.0f - texCoords.y);
	TexCoords = texCoords;
}