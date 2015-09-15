#version 330 core


layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 MVP;

layout(location = 1) in vec3 colorin;

layout(location = 2) in vec3 normals;


uniform mat4 modelMatrix;
uniform mat4 normalMatrix;
uniform mat4 view;

out vec4 colores;

smooth out vec3 vVaryingNormal;
smooth out vec3 vLightDir;
smooth out vec3 diffuseColor;
smooth out vec3 vPosition3;


out Luz
{
  vec3 vertex_camera;
  vec3 normal_camera;
} vLuz;


void main(){
  diffuseColor = colorin;
  vec4 pos4 = modelMatrix * vec4(vertexPosition_modelspace, 1);
  vLuz.vertex_camera = pos4.xyz;
  vLuz.normal_camera = vec3(normalMatrix * vec4(normals, 0));
  gl_Position = MVP * vec4(vertexPosition_modelspace, 1.0);
}

