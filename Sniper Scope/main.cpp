
// T1 - CGA


/*
Luiz José Schirmer Silva  - 201010354


w - anda pra frente
s - pra tras
a - esquerda
d - direita

q - aumenta zoom
e - diminui zoom
esc - termina


ativa a mira se ficar pressionando botão esquerdo do mouse


*/
#include "GL/glew.h"
#include "GL/glut.h" 
#include "glsl.h"
#include "Bmp.h"
#include "cam.h"
#include "matriz.h"
#include <time.h>


#include <stdio.h>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720
#define RECT_SIZE 5
#define TEXTURE_WIDTH 1280
#define TEXTURE_HEIGHT 720

using namespace std;

bool move_foward = false;
bool move_back = false;
bool move_left = false;

clock_t time_now, move_timer = 0;

float desloc = 0;

int fps = 0;
int frames = 0;
int last_time = 0;

Glsl *shader1;
Glsl *shader2;
cam* camera;

float x = 0;

float pos_x;
float pos_y;

GLint loc_u_texture1;
GLint loc_u_texture2;
GLint loc_u_textureMap;


GLuint texture1;
GLuint texture2;
GLuint textureWall;
GLuint textureFloor;
GLuint textureSky;
GLuint alvo;

Bmp *img;
unsigned char *data;

bool mirar = false;


bool key_states[256];
bool mouse_moves[4];

double zoom = 25;

void initgl(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);

    glShadeModel (GL_SMOOTH);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glGenTextures( 1, &texture1 );
    glBindTexture( GL_TEXTURE_2D, texture1 );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);

    glGenTextures( 1, &texture2 );
    glBindTexture( GL_TEXTURE_2D, texture2 );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);

    img = new Bmp("texture/wall.bmp");
    img->convertBGRtoRGB();
    data = img->getImage();
    if( data == NULL ) 
    {
        printf("erro");	
        exit(0);
    }

    glGenTextures( 1, &textureWall );
    glBindTexture( GL_TEXTURE_2D, textureWall );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0, GL_RGB, img->getWidth(),img->getHeight(),0, GL_RGB, GL_UNSIGNED_BYTE, data);
    delete img;

    img = new Bmp("texture/floor.bmp");
    img->convertBGRtoRGB();
    data = img->getImage();
    if( data == NULL ) 
    {
        printf("erro");	
        exit(0);
    }

    glGenTextures( 1, &textureFloor );
    glBindTexture( GL_TEXTURE_2D, textureFloor );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0, GL_RGB, img->getWidth(),img->getHeight(),0, GL_RGB, GL_UNSIGNED_BYTE, data);
    delete img;

	img = new Bmp("texture/sky.bmp");
    img->convertBGRtoRGB();
    data = img->getImage();
    if( data == NULL ) 
    {
        printf("erro");	
        exit(0);
    }

    glGenTextures( 1, &textureSky );
    glBindTexture( GL_TEXTURE_2D, textureSky );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0, GL_RGB, img->getWidth(),img->getHeight(),0, GL_RGB, GL_UNSIGNED_BYTE, data);
    delete img;


	img = new Bmp("texture/alvo.bmp");
    img->convertBGRtoRGB();
    data = img->getImage();
    if( data == NULL ) 
    {
        printf("erro");	
        exit(0);
    }

    glGenTextures( 1, &alvo );
    glBindTexture( GL_TEXTURE_2D, alvo );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0, GL_RGB, img->getWidth(),img->getHeight(),0, GL_RGB, GL_UNSIGNED_BYTE, data);
    delete img;

    glActiveTexture(GL_TEXTURE0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, texture1 );

    glActiveTexture(GL_TEXTURE1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, texture2 );

    glActiveTexture(GL_TEXTURE2);
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, textureWall );

    glActiveTexture(GL_TEXTURE3);
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, textureFloor );
	

	glActiveTexture(GL_TEXTURE4);
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, textureSky );
	
	glActiveTexture(GL_TEXTURE5);
    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, alvo );

}

void alvo_look(void){

	glBindTexture(GL_TEXTURE_2D, alvo);
    glUniform1i(loc_u_textureMap, 5);
   
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(200.f  ,50.f,-200.f  );
    glTexCoord2f(10, 0);
    glVertex3f(-200.f,50.f,-200.f );
    glTexCoord2f(10, 1);
    glVertex3f(-200.f,0.f,-200.f );
    glTexCoord2f(0, 1);
    glVertex3f(200.f  ,0.f,-200.f  );
    glEnd();

}

void ceu(void){

	glBindTexture(GL_TEXTURE_2D,textureSky);
    glUniform1i(loc_u_textureMap, 4);
   
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-15000.f,1000.f,-15000.f );
    glTexCoord2f(50, 0);
    glVertex3f(-15000.f,1000.f,15000.f );
    glTexCoord2f(50, 50);
    glVertex3f(15000.f  ,1000.f,15000.f  );
    glTexCoord2f(0, 50);
    glVertex3f(15000.f  ,1000.f,-15000.f );
    glEnd();

}


void chao(void){
	
	glBindTexture(GL_TEXTURE_2D,textureFloor);
    glUniform1i(loc_u_textureMap, 3);
   
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-2000.f,-1.f,-2000.f );
    glTexCoord2f(50, 0);
    glVertex3f(-2000.f,-1.f,2000.f );
    glTexCoord2f(50, 50);
    glVertex3f(2000.f  ,-1.f,2000.f  );
    glTexCoord2f(0, 50);
    glVertex3f(2000.f  ,-1.f,-2000.f );
    glEnd();

}


void paredes(void){
	
	glBindTexture(GL_TEXTURE_2D,textureWall);
    glUniform1i(loc_u_textureMap, 2);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-2000.f,500.f,2000.f );
    glTexCoord2f(30, 0);
    glVertex3f(-2000.,500.f,-2000.f );
    glTexCoord2f(30, 3);
    glVertex3f(-2000.f,0.f,-2000.f );
    glTexCoord2f(0, 3);
    glVertex3f(-2000.f,0.f,2000.f );
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(2000.f  ,500.f,2000.f  );
    glTexCoord2f(30, 0);
    glVertex3f(-2000.f,500.f,2000.f );
    glTexCoord2f(30, 3);
    glVertex3f(-2000.f,0.f,2000.f );
    glTexCoord2f(0, 3);
    glVertex3f(2000.f  ,0.f,2000.f  );
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(2000.f  ,500.f,-2000.f );
    glTexCoord2f(30, 0);
    glVertex3f(2000.f  ,500.f,2000.f  );
    glTexCoord2f(30, 3);
    glVertex3f(2000.f  ,0.f,2000.f  );
    glTexCoord2f(0, 3);
    glVertex3f(2000.f  ,0.f,-2000.f );
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-2000.f,500.f,-2000.f );
    glTexCoord2f(30, 0);
    glVertex3f(2000.f  ,500.f,-2000.f );
    glTexCoord2f(30, 3);
    glVertex3f(2000.f  ,0.f,-2000.f );
    glTexCoord2f(0, 3);
    glVertex3f(-2000.f,0.f,-2000.f );
    glEnd();

}


void desenhaCena(void){


	glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMultMatrixf(camera->gera_rotate_cam());
	glTranslatef(camera->position->get(0,0),-camera->position->get(1,0),camera->position->get(2,0));
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	shader1->setActive(true);
	chao();
	paredes();
	ceu();
	alvo_look();
}


void desenha_mapa(void){

	glPushMatrix();
    
	if(mirar == true){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawBuffer(GL_BACK);
		glReadBuffer(GL_BACK);
		glViewport(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(45, (double)WIDTH/(double)HEIGHT, 1.0, 200000);
		desenhaCena();
		glFlush();
		glBindTexture(GL_TEXTURE_2D, texture2);
		glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0);
		glBindTexture(GL_TEXTURE_2D, 0);

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawBuffer(GL_BACK);
		glReadBuffer(GL_BACK);

		glViewport(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(zoom, (double)WIDTH/(double)HEIGHT, 1.0, 200000);
		desenhaCena();
		glFlush ();  
		glBindTexture(GL_TEXTURE_2D, texture1);
		glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0);
		glBindTexture(GL_TEXTURE_2D, 0);

		shader2->setActive(true);
		glUniform1i(loc_u_texture1, 0);
        glUniform1i(loc_u_texture2, 1);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, WIDTH, 0, HEIGHT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glBindTexture(GL_TEXTURE_2D, texture2);
        glBegin(GL_QUADS);
        glTexCoord2f(1, 1);  
		glVertex2d(WIDTH,HEIGHT);
        glTexCoord2f(0, 1);  
		glVertex2d(0,HEIGHT);
        glTexCoord2f(0, 0);  
		glVertex2d(0,0);
        glTexCoord2f(1, 0);  
		glVertex2d(WIDTH,0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, 0);
	}
	
	else{
		
		glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
		gluPerspective(45,(double)WIDTH/(double)HEIGHT, 1.0, 200000);
		desenhaCena();
	}
    glEnd();
    glPopMatrix();
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

	if(key_states['q']){

		if(zoom > 5){
			zoom-=5;
		}
	}

	if(key_states['e']){
		if(zoom < 45){
			zoom+=5;
		}
	}
	if(key_states[27]){
		exit(0);
	}
}

void display(void){
	
	

	time_now = clock();
	
	if(time_now - move_timer > CLK_TCK/30){
	   move_timer = time_now;
	   key_Op();
	   mouse_move();
	}
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (double)WIDTH/(double)HEIGHT, 1.0, 200000);
	desenha_mapa();
	glPopMatrix();
	glutSwapBuffers();
}





void key(unsigned char key, int x, int y){
	
	key_states[key] = true;
	
}

void key_up(unsigned char key, int x, int y){
	
	key_states[key] = false;

}

void mouse_1( int button,int state,int x,int y){


	mirar = mirar ^ 1; 
	glUniform1f(pos_x,x);
	glUniform1f(pos_y,y);
	cout << x << " " << y << endl;
	
	
}

void move(int x,int y){

	glUniform1f(pos_x,x);
	glUniform1f(pos_y,y);


	if( (x + 150) >= WIDTH){
		mouse_moves[0] = true;
		
	}
	
	if( (x - 150) <= 0){
		mouse_moves[1] = true;
		

	}
	
	if( (y + 150) >= HEIGHT){
		mouse_moves[2] = true;
		
	}
	if( (y - 150) <= 0){
		mouse_moves[3] = true;
		
	}

}


void reshape(int w, int h){
	
	glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,WIDTH,HEIGHT);
    gluPerspective(45, (double)WIDTH/(double)HEIGHT, 1.0, 20000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}



int main(int argc, char** argv)
{
	
	
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutInitWindowPosition(200,200);
	glutCreateWindow("shooter - T1");

	glutKeyboardFunc(key);
	glutKeyboardUpFunc(key_up);
	glutMouseFunc(mouse_1);
	glutMotionFunc(move);
    glutPassiveMotionFunc(move);
	glutDisplayFunc(display);
    glutIdleFunc(display);
	glutReshapeFunc(reshape);

	
	
	shader1 = new Glsl("tex.vert", "tex.frag");
    shader1->setActive(true);


	shader2 = new Glsl("mira.vert","mira.frag");
	shader2->setActive(false);

	camera = new cam();

	initgl();

	loc_u_textureMap = shader1->getUniformLoc("texture");
	loc_u_texture1 = shader2->getUniformLoc("texture_0");
    loc_u_texture2 = shader2->getUniformLoc("texture_1");
	pos_x = shader2->getUniformLoc("pos_x");
    pos_y = shader2->getUniformLoc("pos_y");

	
	glutMainLoop();

	return 0;
}

