#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoords;

out vec4 vertexColor;
out vec2 texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    vertexColor = vec4(position, 1.0f);
    texCoords = vec2(textureCoords.x, 1.0f - textureCoords.y);
}