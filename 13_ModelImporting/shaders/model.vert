#version 440 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

/*out VS_OUT
{
	vec3 position;
	vec3 normal;
	vec2 texCoord;
} OUT;*/

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 Position;
out vec3 Normal;
out vec2 TexCoord;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);

	mat3 normalMatrix = mat3(transpose(inverse(model)));
	/*OUT.position = vec3(model * vec4(position, 1.0f));
	OUT.normal = normalMatrix * normal;
	OUT.texCoord = texCoord;*/

	Position = vec3(model * vec4(position, 1.0f));
	Normal = normalMatrix * normal;
	TexCoord = texCoord;
}