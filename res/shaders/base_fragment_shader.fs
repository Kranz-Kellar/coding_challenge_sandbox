#version 330 core

in vec4 vertexColor;
in vec2 texCoords;
out vec4 color;

uniform sampler2D testTexture;

void main() {
  
        color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
