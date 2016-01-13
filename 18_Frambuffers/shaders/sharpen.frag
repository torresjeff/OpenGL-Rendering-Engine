#version 440 core

out vec4 color;

in vec2 TexCoords;
uniform sampler2D screenTexture;

const float offset = 1.0f/300.0f; //How close around the current pixel are we sampling values.

void main()
{
	vec2 offsets[9] = vec2[]
	(
		//Top-left				//Top-center		//Top-right
		vec2(-offset, offset), vec2(0.0f, offset), vec2(offset, offset),
		//Center-left		 //Current pixel	//Center-right
		vec2(-offset, 0.0f), vec2(0.0f, 0.0f), vec2(offset, 0.0f),
		//Bottom-left			//Bottom-center		//Bottom-right
		vec2(-offset, -offset), vec2(0.0f, -offset), vec2(offset, -offset)
	);

	float kernel[9] = float[]
	(
		-1, -1, -1,
        -1,  9, -1,
        -1, -1, -1
	);

	vec3 sampleTex[9];
	
	for (int i = 0; i < 9; ++i)
	{
		sampleTex[i] = vec3(texture(screenTexture, TexCoords + offsets[i]));
	}

	vec3 col = vec3(0.0f);
	for (int i = 0; i < 9; ++i)
	{
		col += sampleTex[i] * kernel[i];
	}

	color = vec4(col, 1.0f);
}