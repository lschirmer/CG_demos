#version 330 core

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inTexCoord;

uniform mat4 modelMatrix;
uniform mat4 projMatrix;

out vec2 vTexCoord;

void main()
{
  mat4 MP = projMatrix * modelMatrix;
  vTexCoord = inTexCoord;  
  gl_Position = MP * vec4(inPosition, 1.0);
}