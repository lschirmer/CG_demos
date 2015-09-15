//Vert usado para renderizar a cena

#version 130



varying vec3 luz,luz2;
varying vec3 coord; 
varying vec3 color;
varying vec3 normal;

void main()
{	
	coord = gl_Vertex.xyz;		
	
	normal = gl_Normal;

	gl_Position = ftransform();

	
	color = gl_Color.rgb;   

	gl_TexCoord[0] = gl_MultiTexCoord0;  
}
