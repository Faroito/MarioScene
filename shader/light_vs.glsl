#version 430 core

layout (location = 0) in vec3 position;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 proj_matrix;

void main() {
    gl_Position = proj_matrix * view_matrix * model_matrix * vec4(position, 1.0f);
}
