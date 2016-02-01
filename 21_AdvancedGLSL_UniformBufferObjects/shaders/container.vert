#version 440 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

uniform mat4 model;

//use binding point 2 for this uniform block. 
//Both this and "cubemap.vert" shader now share the same uniform block data.
layout (std140, binding = 2) uniform Matrices
{
	uniform mat4 projection;
	uniform mat4 view;
};

out vec3 Position;
out vec3 Normal;
out vec2 TexCoords;

void main()
{
	mat3 normalMatrix = mat3(transpose(inverse(model))); //Prevents unwanted changes on the normal vector when a shape is scaled non-uniformingly,
														// and transforms the normal vector to "world" space (doesn't actually translate).
	gl_Position = projection * view * model * vec4(position, 1.0f);
	Normal = normalMatrix * normal;
	Position = vec3(model * vec4(position, 1.0f));
	TexCoords = texCoords;
}