/*
T2 -CGA 

Luiz José Schirmer Silva - mat :201010354

Para se mover pelo cenário: w -> frente , s-> para trás, a->esq , d->dir

A camera inicia próxima ao chao e perto dos modelos md2. Para mudar a camera e ver melhor o lod precione v.

muda a camera:

c -> aproxima camera;
v -> visão do alto para ver melhor o lod;


Para o LOD foi usada uma técnica parecida com geometric climapping

http://research.microsoft.com/en-us/um/people/hoppe/gpugcm.pdf

Para as animações em md2 foi utilizado o exemplo criado pelo Pozzer.

*/
#include <stdio.h>
#include<fstream>
#include <assert.h>
#include <stdlib.h>
#include "terrain.h"
#include "Bmp.h"
#include "Actor.h"
#include "md2.h"
#include "..\GL\glew.h"
#include "..\GL\glut.h"

#include "..\GL\gl.h"
#include "..\GL\glext.h"
#include "cam.h"

bool volta = false;


terrain Field;

cam* camera;

Actor *actor = NULL;
Actor *actor_2 = NULL;
bool key_states[256];
bool mouse_moves[4];

float x = 30;
static vec3_t   vertexNormals[ NUMVERTEXNORMALS ] = {
   #include   "anorms.h"
};

void initExtension(void){

	glGenBuffersARB = (PFNGLGENBUFFERSARBPROC) wglGetProcAddress("glGenBuffersARB");
    
	glBindBufferARB = (PFNGLBINDBUFFERARBPROC) wglGetProcAddress("glBindBufferARB");

    
	glBufferDataARB = (PFNGLBUFFERDATAARBPROC) wglGetProcAddress("glBufferDataARB");
    
	glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) wglGetProcAddress("*glDeleteBuffersARB");

}
void mouse_move(void){
	
	if(mouse_moves[0] == true){
		camera->dygraus+=2.f;
		mouse_moves[0] = false;
	}
	
	if(mouse_moves[1] == true){
		mouse_moves[1] = false;
		camera->dygraus-=2.f;
	}
	
	if(mouse_moves[2] == true){
		mouse_moves[2]=false;
		camera->dxgraus+=2.f;
	}
	
	if(mouse_moves[3] == true){
		mouse_moves[3] = false;
		camera->dxgraus-=2.f;
	}
}

void key_Op(void){
	
	if(key_states['w']){
		camera->move_frente(5.f);
	}

	if(key_states['s']){
		camera->move_frente(-5.f);
	}
	
	if(key_states['a']){
		camera->move_esq(5.f);
	}

	if(key_states['d']){
		camera->move_esq(-5.f);
	}

	if(key_states['c']){
		
		camera->position->set(1,0,100);
		
	}

	if(key_states['v']){

		camera->position->set(1,0,700);
	}

	if(key_states[27]){
		exit(0);
	}
}



void display (void) {

glClearColor (1,1,1,1.0);
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glDepthFunc(GL_LEQUAL);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glMultMatrixf(camera->gera_rotate_cam());
glTranslatef(camera->position->get(0,0),-camera->position->get(1,0),camera->position->get(2,0));

//cout <<  "x" << camera->position->get(0,0) << endl;
//cout << "z" <<  camera->position->get(2,0) << endl;

glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);

key_Op();
mouse_move();



glColor3f(0,0.5,1);
glPushMatrix();
Field.render(-camera->position->get(0,0),-camera->position->get(2,0));
glPopMatrix();


glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


actor->render();
//glRotatef(45,0,1,0);


glTranslatef(20,0,x);
actor_2->render();

x+=1;

glutSwapBuffers();
}

void Init (void) {
	
   
   glEnable(GL_DEPTH_TEST);

   glDepthFunc(GL_LEQUAL);

   initExtension();

   Field.load("pozzer.raw", 512, 512);
	
   actor   = new Actor();

   actor_2 = new Actor();
   
   //actor   = new Actor();
   actor->loadModel("data/", "dragon.md2", "dragon.bmp"); 
   actor_2->loadModel("data/","marine.md2","marine.bmp"); 
}


void reshape (int w, int h) {
glViewport (0, 0, (GLsizei)w, (GLsizei)h);

glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective (45, (GLfloat)w / (GLfloat)h, 1.0, 10000.0);

glMatrixMode (GL_MODELVIEW);
}


void key(unsigned char key, int x, int y){
	
	key_states[key] = true;
	
}

void key_up(unsigned char key, int x, int y){
	
	key_states[key] = false;

}


void mouse_1( int button,int state,int x,int y){

	//cout << x << " " << y << endl;
	
	
}

void move(int x,int y){



	if( (x + 150) >= 600){
		mouse_moves[0] = true;
		
	}
	
	if( (x - 150) <= 0){
		mouse_moves[1] = true;
		

	}
	
	if( (y + 150) >= 600){
		mouse_moves[2] = true;
		
	}
	if( (y - 150) <= 0){
		mouse_moves[3] = true;
		
	}

}

int main (int argc, char **argv) {

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

glutInitWindowSize(600, 600);
glutInitWindowPosition(100, 100);
glutCreateWindow("welcome to the grid");

Init();
glutDisplayFunc(display);
glutIdleFunc(display);

glutReshapeFunc(reshape);
glutKeyboardFunc(key);
glutKeyboardUpFunc(key_up);
glutMouseFunc(mouse_1);
glutMotionFunc(move);
glutPassiveMotionFunc(move);

camera = new cam();

glutMainLoop ();
return 0;
} 


