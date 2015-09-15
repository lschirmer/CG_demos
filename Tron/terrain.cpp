#include "terrain.h"




terrain::terrain(){

	local = 64;

}

terrain::~terrain(){


}


bool terrain::Init(void){

	
	//glGenBuffersARB(1,&VBOvertices);
	//glBindBufferARB(GL_ARRAY_BUFFER_ARB,VBOvertices);
	//glBufferDataARB(GL_ARRAY_BUFFER_ARB,vertex_count*3*sizeof(float),vertices,GL_STATIC_DRAW_ARB);

	/*delete []vertices;
	vertices=NULL;*/

	return true;
}


bool terrain::load(char *name,int width,int height){


	FILE* fp;


	l_widht = width +1;
	l_height = height +1;

	fp = fopen(name,"rb"); 

	fread(the_grid,sizeof(unsigned char),(width+1)*(height+1),fp);
	
	fclose(fp);

	vertex_count = (int) (height*width*12);

	vertices = new vert[vertex_count];


	int index =0;
	

	for(int x = 0; x<width-1;x++){
		for(int z = 0;z < height-1;z++){
			if(index <= vertex_count){
			vertices[index].x = x*10;
			vertices[index].y = the_grid[x][z];
			vertices[index].z = z*10;

			index++;

			vertices[index].x = x*10;
			vertices[index].y = the_grid[x][z+1];
			vertices[index].z = (z+1)*10;

			index++;
			
			vertices[index].x = (x+1)*10;
			vertices[index].y = the_grid[x+1][z];
			vertices[index].z = z*10;

			index++;

			vertices[index].x = (x+1)*10;
			vertices[index].y = the_grid[x+1][z+1];
			vertices[index].z = (z+1)*10;

			index++;
			
			vertices[index].x = x*10;
			vertices[index].y = the_grid[x][z];
			vertices[index].z = z*10;

			index++;

			vertices[index].x = (x+1)*10;
			vertices[index].y = the_grid[x+1][z];
			vertices[index].z = z*10;

			index++;

			vertices[index].x = x*10;
			vertices[index].y = the_grid[x][z+1];
			vertices[index].z = (z+1)*10;

			index++;
			
			vertices[index].x = (x+1)*10;
			vertices[index].y = the_grid[x+1][z+1];
			vertices[index].z = (z+1)*10;

			index++;

			vertices[index].x = x*10;
			vertices[index].y = the_grid[x][z+1];
			vertices[index].z = (z+1)*10;

			index++;

			vertices[index].x = (x+1)*10;
			vertices[index].y = the_grid[x+1][z];
			vertices[index].z = z*10;

			index++;
			}
		}
	}

	Init();
	


	return true;
}


float terrain::dist(float c_x,float c_y,float g_x,float g_y){

	float a = (c_x - g_x)*(c_x - g_x);
	float b = (c_y - g_y)*(c_y - g_y);

	
	return sqrt(a + b);
}


void terrain::segment(float c_x,float c_z){


	int x = (int)c_x/area;
	int z = (int)c_z/area;

	x_min = x-local;
	x_max = x+local;
	z_min = z-local;
	z_max = z+local;

}


void terrain::render_tarea2(void){
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glBegin(GL_TRIANGLES);
		
		
	for (int x= x_min; x < x_max;x+=lod){
		for(int z= z_min; z< z_max;z+=lod){
				
		  if( (x > 0 && z >0) && (x+lod < l_widht && z+lod < l_height)){
			  if(z==z_min){
					    
						glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
						glVertex3f(((x+(x+lod))/2)*(area),the_grid[(x+(x+lod))/2][z+lod],(z+lod)*(area));
						glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

						glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
						glVertex3f(x*(area),the_grid[x][z],z*(area));
						glVertex3f(((x+(x+lod))/2)*(area),the_grid[(x+(x+lod))/2][z+lod],(z+lod)*(area));

						glVertex3f(x*(area),the_grid[x][z],z*(area));
						glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));
						glVertex3f(((x+(x+lod))/2)*(area),the_grid[(x+(x+lod))/2][z+lod],(z+lod)*(area));
				
				}  else if(z == z_tmax){
						glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
						glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));
						glVertex3f(((x+(x+lod))/2)*(area),the_grid[(x+(x+lod))/2][z],(z)*(area));

						glVertex3f(((x+(x+lod))/2)*(area),the_grid[(x+(x+lod))/2][z],(z)*(area));
						glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));
						glVertex3f((x)*(area),the_grid[x][z],(z)*(area));

						glVertex3f(((x+(x+lod))/2)*(area),the_grid[(x+(x+lod))/2][z],(z)*(area));
						glVertex3f((x)*(area),the_grid[x][z],(z)*(area));
						glVertex3f((x)*(area),the_grid[x][z+lod],(z+lod)*(area));
				}
		  }
		}
	}
	glEnd();
}


void terrain::render_tarea1(void){
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glBegin(GL_TRIANGLES);
		
		
		for (int x= x_min; x < x_max;x+=lod){
			for(int z= z_min; z< z_max;z+=lod){
				
				if( (x > 0 && z >0) && (x+lod < l_widht && z+lod < l_height)){
					if( x == x_min){
					   
					   glVertex3f(x*(area),the_grid[x][z],z*(area));
					   glVertex3f((x+lod)*(area),the_grid[x+lod][(z+(z+lod))/2],(((z+(z+lod))/2)*(area)));
					   glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));

					   glVertex3f(x*(area),the_grid[x][z],z*(area));
					   glVertex3f((x+lod)*(area),the_grid[x+lod][(z+(z+lod))/2],(((z+(z+lod))/2)*(area)));
					   glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));

					   glVertex3f((x+lod)*(area),the_grid[x+lod][(z+(z+lod))/2],(((z+(z+lod))/2)*(area)));
					   glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));
					   glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));
				  }
				  else if(x == x_tmax){
						
						glVertex3f(x*(area),the_grid[x][z],z*(area));
						glVertex3f(x*(area),the_grid[x][(z+(z+lod))/2],((z+(z+lod))/2)*(area));
						glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));

						glVertex3f(x*(area),the_grid[x][(z+(z+lod))/2],((z+(z+lod))/2)*(area));
						glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));
						glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

						glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
						glVertex3f(x*(area),the_grid[x][(z+(z+lod))/2],((z+(z+lod))/2)*(area));
						glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

				}

			 }
		  }
	  }
	  glEnd();
}


void terrain::render_tarea(void){
		
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glBegin(GL_TRIANGLES);
		
		
		for (int x= x_min; x < x_max;x+=lod){
			for(int z= z_min; z< z_max;z+=lod){
				
				if( (x > 0 && z >0) && (x+lod < l_widht && z+lod < l_height)){
					
					if( (x == x_min && z == z_min) ||(x == x_max-lod && z == z_max-lod) ){

					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));
				} 

			    else if( (x==x_min && z ==z_max-lod)||(x==x_max-lod && z == z_min)){
					  
					  glVertex3f(x*(area),the_grid[x][z],z*(area));
					  glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
					  glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));

					  glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
					  glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));
					  glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));
				}

				
			  }
			}
		}
		glEnd();
}


void terrain::new_segment(void){

	x_min -= local*lod;
	x_max += local*lod;
	z_min -= local*lod;
	z_max += local*lod;
}


void terrain::transition(void){

	x_tmin = x_min;
	x_tmax = x_max;
	z_tmin  = z_min;
	z_tmax = z_max;

	x_min -= lod;
	x_max += lod;
	z_min -= lod;
	z_max += lod;
	
	
}

void terrain::render(float c_x,float c_z){
	
		glColor3f(0,0,0);
	    
		segment(c_x,c_z);
		
		lod = 1;

		glBegin(GL_LINES);
		
		for (int x = x_min; x < x_max;x++){
			for(int z = z_min; z< z_max;z++){
				
				if( (x > 0 && z >0) && (x+lod < l_widht && z+lod < l_height)){
					
					glVertex3f(x*(area*lod),the_grid[x][z],z*(area*lod));
					
					glVertex3f(x*(area*lod),the_grid[x][z+1],(z+1)*(area*lod));
					
					glVertex3f((x+1)*(area*lod),the_grid[x+1][z],(z)*(area*lod));

					glVertex3f((x+1)*(area*lod),the_grid[x+1][z+1],(z+1)*(area*lod));
					
					glVertex3f(x*(area*lod),the_grid[x][z],z*(area*lod));

					glVertex3f((x+1)*(area*lod),the_grid[x+1][z],z*(area*lod));
					
					glVertex3f(x*(area*lod),the_grid[x][z+1],(z+1)*(area*lod));

					glVertex3f((x+1)*(area*lod),the_grid[x+1][z+1],(z+1)*(area*lod));

					glVertex3f((x+1)*(area*lod),the_grid[x+1][z],z*(area*lod));

					glVertex3f(x*(area*lod),the_grid[x][z+1],(z+1)*(area*lod));
				}
				
			}
		}
		glEnd();

		local/=2;
		local--;
		lod *=2;
		
		transition();
		
		render_tarea();
		render_tarea1();
		render_tarea2();
		
		x_tmin = x_min;
		x_tmax = x_max;
		z_tmin = z_min;
		z_tmax = z_max;

		x_min -= local * lod;
		x_max += local * lod;
		z_min -= local * lod;
		z_max += local * lod;

		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glBegin(GL_TRIANGLES);
		for(int x = x_min; x < x_max; x+=lod){
			for(int z = z_min; z < z_max; z+=lod){
				if(((x >= x_tmax || x <= x_tmin)||(z >= z_tmax || z <= z_tmin)) && x >=0 && z>=0 && (x+lod < l_widht) && (z+lod < l_height) ){
					
					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

				}
			}
		}
		
		glEnd();

		
		
		lod *=2;

		transition();
		
		render_tarea();
		render_tarea1();
		render_tarea2();

		x_tmin = x_min;
		x_tmax = x_max;
		z_tmin = z_min;
		z_tmax = z_max;


		x_min -= local * lod;
		x_max += local * lod;
		z_min -= local * lod;
		z_max += local * lod;

		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glBegin(GL_TRIANGLES);
		for(int x = x_min; x < x_max; x+=lod){
			for(int z = z_min; z < z_max; z+=lod){
				
				if(((x >= x_tmax || x <= x_tmin)||(z >= z_tmax || z <= z_tmin)) && x >=0 && z>=0 && (x+lod < l_widht) && (z+lod < l_height) ){
					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

				}
			}
		}
		
		glEnd();

		

		
		lod *=2;
	

		transition();
		
		render_tarea();
		render_tarea1();
		render_tarea2();

		x_tmin = x_min;
		x_tmax = x_max;
		z_tmin = z_min;
		z_tmax = z_max;

		x_min -= local * lod;
		x_max += local * lod;
		z_min -= local * lod;
		z_max += local * lod;
	

		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glBegin(GL_TRIANGLES);
		for(int x = x_min; x < x_max; x+=lod){
			for(int z = z_min; z < z_max; z+=lod){
				if(((x >= x_tmax || x <= x_tmin)||(z >= z_tmax || z <= z_tmin)) && x >=0 && z>=0 && (x+lod < l_widht) && (z+lod < l_height) ){
					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

				}
			}
		}
		
		glEnd();

		

		lod *=2;

		transition();
		
		render_tarea();
		render_tarea1();
		render_tarea2();

		x_tmin = x_min;
		x_tmax = x_max;
		z_tmin = z_min;
		z_tmax = z_max;

		x_min -= local * lod;
		x_max += local * lod;
		z_min -= local * lod;
		z_max += local * lod;
		

		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glBegin(GL_TRIANGLES);
		for(int x = x_min; x < x_max; x+=lod){
			for(int z = z_min; z < z_max; z+=lod){
				if(((x >= x_tmax || x <= x_tmin)||(z >= z_tmax || z <= z_tmin)) && x >=0 && z>=0 && (x+lod < l_widht) && (z+lod < l_height) ){
					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z],z*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

					glVertex3f(x*(area),the_grid[x][z],z*(area));
					glVertex3f(x*(area),the_grid[x][z+lod],(z+lod)*(area));
					glVertex3f((x+lod)*(area),the_grid[x+lod][z+lod],(z+lod)*(area));

				}
			}
		}
		
		glEnd();

		

		x_min = 0;
		x_max = l_widht;
		z_min = 0;
		z_max = l_height;
		local = 64;
		lod = 1;
}
