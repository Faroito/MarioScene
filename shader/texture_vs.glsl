#version 410 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texture;

out vec4 vertexColor;
out vec2 texCoord;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 proj_matrix;

void main() {
    vertexColor = color;
    texCoord = texture;
    gl_Position = proj_matrix * view_matrix * model_matrix * vec4(position, 1.0f);
}
