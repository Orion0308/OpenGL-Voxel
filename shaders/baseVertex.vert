#version 330 core
layout(location = 0) in vec3 vertexCords;
layout(location = 1) in vec2 textureCords;
layout(location = 2) in vec3 vertexOffset;

out vec2 textureCordsOut;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * vec4(vertexCords + vertexOffset, 1.0f);
    textureCordsOut = textureCords;
}
