#version 430 core

layout (location = 0) in vec3 position; // The position variable has attribute position 0
layout (location = 1) in vec3 color;

out vec4 vertexColor;

void main()
{
    gl_Position = vec4(position, 1.0f);
    vertexColor = vec4(color, 1.0f);
}
