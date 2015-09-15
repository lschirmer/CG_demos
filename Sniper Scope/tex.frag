//Frag usado para renderizar a cena

#version 130

uniform sampler2D texture;


uniform float pos_x;
uniform float pos_y;


void main()
{		
	 vec2 position = gl_TexCoord[0].st;
	 vec3 cor;
	
	 cor = texture2D(texture,position).rgb;
	 gl_FragColor = vec4(cor,1);
	
	
}