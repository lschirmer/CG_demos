
#include<GL\glew.h>
#include<GL\glut.h>
#include<iostream>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "objeto.h"
#include "Thatshader.h"
#include "scene.h"

#define M_PI 3.14
#define Esferas_X 10
#define Esferas_Y 10

GLuint progID,progID2; 
GLuint fb,fb_pos,fb_norm,fb_material;


ThatShader *shader1, *shader2;

grid *chao;
Sphere** esfera;
scene *quad;
Sphere** lightSphere;

int Num_Spheres;

glm::mat4 view;
glm::mat4 projection;

int shader_flag = 0;
GLfloat lightCoords[50 * 4];

void create_FBO(){
	fb = 0;
	
	glGenFramebuffers(1,&fb);
	glBindFramebuffer(GL_FRAMEBUFFER, fb);
	glGenTextures(1,&fb_pos);
	glBindTexture(GL_TEXTURE_2D,fb_pos);
	glTexImage2D (
		GL_TEXTURE_2D,
		0,
		GL_RGB16F,
		800,
		600,
		0,
		GL_RGB,
		GL_FLOAT,
		NULL
	);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glGenTextures (1, &fb_norm);
	glBindTexture (GL_TEXTURE_2D, fb_norm);
	glTexImage2D (
		GL_TEXTURE_2D,
		0,
		GL_RGB16F,
		800,
		600,
		0,
		GL_RGB,
		GL_FLOAT,
		NULL
	);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);


	glGenTextures(1, &fb_material);
	glBindTexture(GL_TEXTURE_2D, fb_material);
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGB16F,
		800,
		600,
		0,
		GL_RGB,
		GL_FLOAT,
		NULL
		);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);


	
	glFramebufferTexture2D (
	 GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, fb_material, 0
	);
	glFramebufferTexture2D (
	 GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, fb_norm, 0
	);

	glFramebufferTexture2D(
		GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, fb_pos, 0
		);
	unsigned int rb = 0;
	
	glGenRenderbuffers(1, &rb);
	glBindRenderbuffer(GL_RENDERBUFFER, rb);
	glRenderbufferStorage(
		GL_RENDERBUFFER, GL_DEPTH_COMPONENT, 800, 600
		);
	glFramebufferRenderbuffer(
		GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rb
		);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	GLenum draw_bufs[] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1,GL_COLOR_ATTACHMENT2 };
	glDrawBuffers(3, draw_bufs);
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}


static void Light_generation(){
	
	for (int i = 0; i < 50; i++) {
		lightCoords[i * 4] = -sin((float)i*0.5f) * 30.f;
		lightCoords[i * 4 + 1] = 2 + rand() % 10;
		lightCoords[i * 4 + 2] = cos((float)i*0.5f) * 30.f;
		lightCoords[i * 4 + 3] = 1.f;
	}
}

static void Init()
{
	chao = new grid(50, 50);
	chao->criaGrid();
	chao->setCores(0, 0, 1);
	chao->criabuff();
	chao->setModelMatrix(glm::scale(glm::vec3(30, 1, 30)) * glm::rotate(static_cast<float>(M_PI / 2), glm::vec3(1, 0, 0)));
	chao->setNormalMatrix(view);

	view = glm::lookAt(glm::vec3(14.5, 10, 40), glm::vec3(14.5, 0, 0), glm::vec3(0, 1, 0));
	projection = glm::perspective(static_cast<float>(M_PI/4), 800.f / 600.f, 1.f, 100.f);
	
	create_FBO();

	//gerar luzes

	quad = new scene();
	quad->setModelMatrix(glm::mat4(1.f));
	quad->setNormalMatrix(view);
	quad->quad_gen();

	shader1 = new ThatShader();
	shader1->init("vertex.vert", "fragment.frag");
	shader1->compile();
	progID = shader1->Linker();
	

	shader2 = new ThatShader();
	shader2->init("vertex2.vert", "fragment2.frag");
	shader2->compile();
	progID2 = shader2->Linker();
	
	Num_Spheres = Esferas_X * Esferas_Y;

	esfera = new Sphere*[Num_Spheres];
	
	for (int i = 0; i < Num_Spheres; i++) {
		esfera[i] = new Sphere(20, 10);
		esfera[i]->CriaSphere();
		esfera[i]->setCores(1, 0, 0);
		esfera[i]->criabuff();
	}
	
	for (int i = 0; i < Esferas_X; i++) {
		for (int j = 0; j < Esferas_Y; j++) {
			esfera[i * Esferas_X + j]->setModelMatrix(glm::translate(glm::vec3(3 * i + 1, 1, 3 * j)));
			esfera[i * Esferas_X + j]->setNormalMatrix(view);
		}
	}

	Light_generation();
}


static void second_pass(){
	
	// deferred pass

	shader2->Load();
	GLuint idx = glGetUniformBlockIndex(shader2->getProgramID(), "LightSource");
	glUniformBlockBinding(shader2->getProgramID(), idx, 1);
	GLuint lightbuff;
	glGenBuffers(1, &lightbuff);
	glBindBuffer(GL_UNIFORM_BUFFER, lightbuff);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(GLuint)* 4 * 50, lightCoords, GL_STATIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, 1, lightbuff);

	GLuint id2 = shader2->GetLocation(shader2->getProgramID(), "diffuseMap");
	shader2->Uniform1i(id2, 0);
	id2 = shader2->GetLocation(shader2->getProgramID(), "normalMap");
	shader2->Uniform1i(id2, 1);
	id2 = shader2->GetLocation(shader2->getProgramID(), "vertexMap");
	shader2->Uniform1i(id2, 2);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, fb_material);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, fb_norm);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, fb_pos);
	
	GLuint id = shader2->GetLocation(shader2->getProgramID(), "modelMatrix");
	shader2->UniformMatrix(id, quad->getModelMatrix());
	id = shader2->GetLocation(shader2->getProgramID(), "viewMatrix");
	shader2->UniformMatrix(id, view);
	id = shader2->GetLocation(shader2->getProgramID(), "projMatrix");
	shader2->UniformMatrix(id, glm::ortho(-1.f, 1.f, -1.f, 1.f));
	quad->bind();
	quad->draw();
}

static void Draw_theShader(ThatShader *shader){


	GLuint mview = shader->GetLocation(progID, "view");
	shader->UniformMatrix(mview, view);

	glm::mat4 MVP2;
	GLuint vish = shader->GetLocation(progID, "projection");
	shader->UniformMatrix(vish, projection);

	for (int i = 0; i < Num_Spheres; i++){

		GLuint v = shader->GetLocation(progID, "MVP");
		MVP2 = projection * view * esfera[i]->getModelMatrix();
		shader->UniformMatrix(v, MVP2);

		GLuint mat2 = shader->GetLocation(progID, "modelMatrix");
		glm::mat4 MV = view * esfera[i]->getModelMatrix();
		shader->UniformMatrix(mat2, MV);

		GLuint mat3 = shader->GetLocation(progID, "normalMatrix");
		shader->UniformMatrix(mat3, esfera[i]->getNormalMatrix());

		esfera[i]->Draw();
	}


	GLuint bla = shader->GetLocation(progID, "MVP");
	glm::mat4 MVP = projection * view * chao->getModelMatrix();
	shader->UniformMatrix(bla, MVP);
	GLuint mat2 = shader->GetLocation(progID, "modelMatrix");
	glm::mat4 MV = view * chao->getModelMatrix();
	shader->UniformMatrix(mat2, MV);
	GLuint mat3 = shader->GetLocation(progID, "normalMatrix");
	shader->UniformMatrix(mat3, chao->getNormalMatrix());
	chao->Draw();
	
}


// Draw scene 
static void DrawScene()
{	
	
	glBindFramebuffer(GL_FRAMEBUFFER, fb);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	shader1->Load();
	progID = shader1->getProgramID();
	Draw_theShader(shader1);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader2->Load();
	second_pass();
}

// Display callback
static void Display(void)
{
	DrawScene();
	glutSwapBuffers();
}

// Reshape callback
static void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

// Keyboard callback
static void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: exit(0); 
			break;
		case 'a': 
			shader_flag = 0;
			break;
		case 's':
			shader_flag = 1;
			break;
	}
}

static void InitGlew(){

	//abre a Glew e testa
	GLenum err = glewInit();
	if (GLEW_OK != err){
		fprintf(stderr, "ERRO NA GLEW: %s\n", glewGetErrorString(err));
		system("Pause");
		exit(-1);
	}
	//inicia GL
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glPointSize(5);

}
// Main function
int main(int argc, char* argv[])
{
	// open GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(800, 600);

	// create window
	glutCreateWindow("Balls of Steel");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutIdleFunc(Display);
	// initiate OpenGL context
	InitGlew();
	Init();
	// interact...
	glutMainLoop();
	return 0;
}