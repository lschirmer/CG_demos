
uniform sampler2D texture_0; //se nao for inicializada, vale 0, referente a textura 0
uniform sampler2D texture_1; //se nao for inicializada, vale 0, referente a textura 0

uniform float pos_x;
uniform float pos_y;


varying float  x_coord;
varying float  y_coord;



//filtro gaussiano

const vec2  gaussFilter[17] = 
{
	-8.0,	0.00000067,
	-7.0,   0.00002292,
	-6.0,   0.00019117,
	-5.0,	0.00002292,
	-4.0,   0.00019117, 
	-3.0,	0.017625,
	-2.0,	0.09575,
	-1.0,	0.254375,
	0.0,	0.3325,
	1.0,	0.254375,
	2.0,	0.09675,
	3.0,	0.017625,
	4.0,	0.00019117,
	5.0,    0.00002292,
	6.0,	0.00019117,
	7.0,    0.00002292,
	8.0,	0.00000067,
	
};


void main()
{
   
   vec2 mouse;
   vec2 position = gl_TexCoord[0].st;
   vec3 cor_1;
   vec3 cor_2;
   vec3 cor;
   vec4 color;



   vec2 pos = vec2(gl_FragCoord.x,gl_FragCoord.y);
   

   mouse.x =  640 - pos.x;
   mouse.y = 360 - pos.y;
   
   float dist = sqrt((mouse.x)*(mouse.x) + (mouse.y)*(mouse.y));

 
   if(dist < 120.0){	
		

		vec2 p = gl_TexCoord[0].st;		
		
		
		cor = texture2D(texture_0,p).rgb;
		
		
		if( mouse.x > -1.0 && mouse.x < 1.0){
			cor = vec3(0,0,0);
		}
		
		if(mouse.y > -1.0 && mouse.y < 1.0){
			cor = vec3(0,0,0);
		}
		
		gl_FragColor = vec4(cor,1);
     
   }

   else{
		
		if(dist > 120.0 && dist < 130.0) {
			cor_2 = vec3(0,0,0);
			gl_FragColor = vec4(cor_2,1);
		}
		
		else{	
			vec2 p = gl_TexCoord[0].st;
			
			vec2 Scale = vec2(1.0/256.0 , 0.0);

			for(int i = 0; i <17 ; i++){
				color += texture2D( texture_1, vec2( p.x+gaussFilter[i].x*Scale.x, p.y+gaussFilter[i].x*Scale.y ) )*gaussFilter[i].y;			
			}
			gl_FragColor = color;
	   }
  }
   
 } 
  
