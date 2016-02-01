#version 430 core
layout (location = 0) in vec3 position;
out vec3 TexCoords;

//use binding point 2 for this uniform block.
//Both this and "container.vert" shader now share the same uniform block data.
layout (std140, binding = 2) uniform Matrices
{
	uniform mat4 projection;
	uniform mat4 view;
};


void main()
{
    vec4 pos = projection * mat4(mat3(view)) * vec4(position, 1.0f);
    gl_Position = pos.xyww;
    TexCoords = position;
}  