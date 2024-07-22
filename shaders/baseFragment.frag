#version 330 core
out vec4 FragColor;

in vec2 textureCordsOut;

// texture samplers
uniform sampler2D texture;

void main()
{
    FragColor = vec4(1.0, 0.647, 0.0, 1.0);
    //FragColor = texture2D(texture, textureCordsOut);
}
