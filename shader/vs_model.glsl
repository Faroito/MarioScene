#version 120

attribute vec4 position;
attribute vec4 color;

varying vec4 dstColor;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 proj_matrix;

void main() {
    dstColor = color;
    gl_Position = proj_matrix * view_matrix * model_matrix * position;
}
