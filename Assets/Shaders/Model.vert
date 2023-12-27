#version 400 core
 
in vec3 position;
in vec2 textureCoords;

out vec2 pass_texCoords;

uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
void main() {
    gl_Position = model * view * transform * vec4(position, 1.0f);
    pass_texCoords = textureCoords;
}