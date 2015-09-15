

varying float  x_coord;
varying float  y_coord;


void main()
{ 

	gl_Position = ftransform();
	gl_TexCoord[0] = gl_MultiTexCoord0; 	
}
