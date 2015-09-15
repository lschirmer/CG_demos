#version 330 core

layout(location = 0) out float frag;


void main(){
	frag = gl_FragCoord.z;
}