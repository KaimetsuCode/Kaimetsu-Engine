#version 400 core

in vec3 colour;

out vec4 output;

void main() {
    output = vec4(colour, 1.0f);
}