#version 330 core

layout (location = 0) out vec3 Color;
layout (location = 1) out vec3 normal;
layout (location = 2) out vec3 vertex;

in vec3 diffuseColor;

in Luz
{
  vec3 vertex_camera;
  vec3 normal_camera;
} vLuz;

void main()
{
  Color = diffuseColor;
  normal= normalize(vLuz.normal_camera);
  vertex= vLuz.vertex_camera;
}