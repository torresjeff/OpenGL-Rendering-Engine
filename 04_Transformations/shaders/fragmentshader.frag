#version 430 core

out vec4 color;

in vec3 vertexColor;
in vec2 TexCoord; //Estos solo son los coordinates del texture, no el texture como tal

uniform sampler2D ourTexture; //Este si es el texture
uniform sampler2D ourTexture2;

void main()
{
	//To sample the color of a texture we use GLSL's built-in texture function that takes as its first argument a texture sampler and as its second argument the corresponding texture coordinate.
	//The texture function then samples the corresponding color value using the texture parameters we set earlier. The output of this fragment shader is then the (filtered) color of the texture at the (interpolated) texture coordinate.
	//color = texture(ourTexture, TexCoord) * vec4(vertexColor, 1.0f);
	color = mix(texture(ourTexture, TexCoord), texture(ourTexture2, TexCoord), 0.2); //mix: linearly interpolates between two values, based on the third argument (0.2).
}