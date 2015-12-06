#version 430 core

layout (location = 0) in vec3 position;
layout (location = 2) in vec2 texCoord;

out vec3 vertexColor;
out vec2 TexCoord; //Estos solo son los coordinates del texture, no el texture como tal

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	//Note that we read the multiplication from left to right (position -> model -> view -> projection)
	// By multipling the view with the model matrix, we're effectively moving the object in the opposite direction that the camera is supposed to move
	gl_Position = projection * view * model * vec4(position, 1.0f);
	TexCoord = vec2(texCoord.x, 1.0f - texCoord.y); //By default the image is flipped upside down. This is a hack to show the image the way it's supposed to be.
}