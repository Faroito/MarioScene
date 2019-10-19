#version 410 core

in vec3 position;
in vec4 color;

out vec4 vertexColor;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 proj_matrix;

void main() {
    vertexColor = color;
    gl_Position = proj_matrix * view_matrix * model_matrix * vec4(position, 1.0f);
}
