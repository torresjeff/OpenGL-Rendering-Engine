#version 430 core

layout (location = 0) in vec3 position; // The position variable has attribute position 0

void main()
{
    gl_Position = vec4(position, 1.0f);
}
