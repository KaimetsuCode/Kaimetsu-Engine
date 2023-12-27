#version 400 core

in vec2 pass_texCoords;

out vec4 output;

uniform sampler2D textureSampler;

void main() {
    output = texture(textureSampler, pass_texCoords);
}