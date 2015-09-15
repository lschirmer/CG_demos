
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include <GL/glew.h>

#include<glfw3.h>

GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;


#include "objeto.h"
#include "ThatShader.h"
#include "camera.hpp"


ThatShader *shader1, *shader2;
objeto* cena;
GLuint depthProgramID, depthMatrixID;
GLuint quad_programID;
GLuint FramebufferName, programID;
GLuint VertexArrayID;
GLuint quad_vertexbuffer;
GLuint texID;
GLuint TextureID;
GLuint MatrixID;
GLuint ModelMatrixID;
GLuint DepthBiasID;
GLuint ShadowMapID;
GLuint lightInvDirID;
GLuint ViewMatrixID;
GLuint depthTexture;
GLuint Texture;


float a = 2;
float b = 0.5;

glm::mat4 biasMatrix( 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0,0.0, 0.0, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0);

void createFrameBuffer(){
	FramebufferName = 0;
	glGenFramebuffers(1, &FramebufferName);
	glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);	
	glGenTextures(1, &depthTexture);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);

	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);
	glDrawBuffer(GL_NONE);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		exit(1);
	
	static const GLfloat g_quad_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
	};

	glGenBuffers(1, &quad_vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, quad_vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_quad_vertex_buffer_data), g_quad_vertex_buffer_data, GL_STATIC_DRAW);

}


void Init(){

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	shader1 = new ThatShader();
	shader1->init("shader1.vs", "shader1.fs");
	shader1->compile();
	depthProgramID = shader1->Linker();
	shader1->Load();
	depthMatrixID = shader1->GetLocation(depthProgramID, "depthMVP");
	cena = new objeto();
	cena->LoadObjeto();
	cena->criabuff();
	createFrameBuffer();

	shader2 = new ThatShader();
	shader2->init("shader2.vs", "shader2.fs");
	shader2->compile();
	programID = shader2->Linker();
	shader2->Load();
	TextureID = shader2->GetLocation(programID, "myTextureSampler");
	MatrixID = shader2->GetLocation(programID, "MVP");
	ViewMatrixID = shader2->GetLocation(programID, "V");
	ModelMatrixID = shader2->GetLocation(programID, "M");
	DepthBiasID = shader2->GetLocation(programID, "DepthBiasMVP");
	ShadowMapID = shader2->GetLocation(programID, "shadowMap");
	lightInvDirID = shader2->GetLocation(programID, "LightInvDirection_worldspace");
	
		
}

void InitGlew(){

	glewExperimental = true; 
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		exit(1);
	}
}

int main( void )
{
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 5);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow( 1024, 768, "Shadows Mapping pcf", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	InitGlew();
	Init();
	
	float a = 2;
	float b = 5;
	
	do{

		glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);
		glViewport(0,0,1024,1024); 
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK); 

		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader1->Load();


		a += 0.01;
		b += 0.01;
		glm::vec3 lightInvDir = glm::vec3(sin(a), 2, cos(b));
		glm::mat4 depthProjectionMatrix = glm::ortho<float>(-10,10,-10,10,-10,20);
		glm::mat4 depthViewMatrix = glm::lookAt(lightInvDir, glm::vec3(0,0,0), glm::vec3(0,1,0));
		glm::mat4 depthModelMatrix = glm::mat4(1.0);
		glm::mat4 depthMVP = depthProjectionMatrix * depthViewMatrix * depthModelMatrix;

		shader1->UniformMatrix(depthMatrixID, depthMVP);

		cena->attribVertex();
		cena->Draw();
		cena->disableAvertex();

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glViewport(0,0,1024,768); 

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
		shader2->Load();
		computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = getProjectionMatrix();
		glm::mat4 ViewMatrix = getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
		

		glm::mat4 depthBiasMVP = biasMatrix*depthMVP;

		shader2->UniformMatrix(MatrixID, MVP);
		shader2->UniformMatrix(ModelMatrixID, ModelMatrix);
		shader2->UniformMatrix(ViewMatrixID, ViewMatrix);
		shader2->UniformMatrix(DepthBiasID, depthBiasMVP);
		shader2->Uniform3f(lightInvDirID, lightInvDir);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, depthTexture);
		shader2->Uniform(ShadowMapID, 1);
		
		cena->attribVertex();
		cena->attribColor();
		cena->attribNormal();
		cena->Draw();
		cena->disableAvertex();
		cena->disableAcolor();
		cena->disableAnormal();
		
	
		glViewport(0,0,512,512);
		
		glfwSwapBuffers(window);
		glfwPollEvents();

	} 
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );
	
	

	glfwTerminate();

	return 0;
}

