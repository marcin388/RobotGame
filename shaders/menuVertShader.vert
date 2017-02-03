#version 430

layout (location=0) in vec3 VertexPosition;
layout (location=2) in vec2 fragTexCoord;

out vec2 texCoord;

void main()
{
	texCoord = fragTexCoord;

    gl_Position = vec4(VertexPosition,1.0);
}