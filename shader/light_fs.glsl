#version 430 core

out vec4 FragColor;

uniform vec3 ambientLightColor;

void main()
{
    FragColor = vec4(ambientLightColor, 1.0);
}
