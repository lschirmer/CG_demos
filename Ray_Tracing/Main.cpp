

#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include<stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>

#include "Camera.h"
#include "objeto.h"


const int width = 800;
const int height = 600;
int MAX_DEPTH = 6;


bool pthreadOn = false;
bool redisplay = true;
float shininess = pow(2,6);

float pixels[width*height*4];

Camera camera;
std::vector<objeto*> objetos;
std::vector<luz> lamps;


glm::vec3 trace(raio raio,  int  depth);

static void Init ()
{
  glClearColor(1,1,1,1);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_CULL_FACE);
  glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);

  camera.camCreate(glm::vec3(100.0f, 80.0f, -50.0f), glm::vec3(0.0f, 20.0f, 0.0f),glm::vec3(0.0f, 1.0f, 0.0f), 90.f, 30.f, 300.f, (float)width, (float)height);
  objetos.push_back(new espelho(glm::vec3(-80.0f, -50.0f, -100.0f), glm::vec3(90.0f, -45.0f, 100.0f),glm::vec3(1.f,1.0f,1.0f)));
  objetos.push_back(new espelho(glm::vec3(-80.0f, -50.0f, 100.0f),glm::vec3(90.0f, 100.0f, 110.0f),glm::vec3(0.0f,1.f,1.0f)));
  objetos.push_back(new espelho(glm::vec3(-85.0f, -50.0f, -100.0f),glm::vec3(-80.0f, 100.0f, 100.0f),glm::vec3(0.0f,1.f,1.0f)));
 
  objetos.push_back(new esfera(glm::vec3(30.0f, 30.0f, 20.0f), 25.0f,glm::vec3(0.0f,1.0f,0.0f)));
  objetos.push_back(new esfera(glm::vec3(40.0f, -20.0f, 60.0f), 15.0f, glm::vec3(1.0f,0.0f,0.0f)));
  objetos.push_back(new esfera(glm::vec3(30.0f, 30.0f, -30.0f), 20.0f, glm::vec3(0.0f,0.0f,1.0f)));
 

  for(int i = 0 ; i < (int)objetos.size() ; i++)
  {
	  if (i == 0) {
		  objetos[i]->setMaterial(tipo::DEFAULT);
	  }
	  else{
		  objetos[i]->setMaterial(tipo::REFLETIVO);
	  }
   }

  lamps.push_back(
    luz(glm::vec3(60.f, 120.f, 40.f),glm::vec3(1.f,1.f,1.f)));
  lamps.push_back(
    luz(glm::vec3(60.f, 80.f, -40.f),glm::vec3(1.f,1.f,1.f))
    );
}

static void Reshape (int w, int h)
{
  glViewport(0, 0, width, height);
  glutReshapeWindow(width, height);
}


bool shadowed(glm::vec3 point, glm::vec3 lamp_pos)
{
	glm::vec3 dir = lamp_pos - point;
	dir = glm::normalize(dir);
	float max_distance = glm::distance(point, lamp_pos);

	float tmin;
	for (int s = 0; s < (int)objetos.size(); s++)
	{
		glm::vec3 normal;
		raio the_raio;
		the_raio.position = point;
		the_raio.direction = dir;
		if (objetos[s]->Hit(the_raio, tmin, normal))
		{
			if (tmin > 0.1f && tmin <= max_distance)
			{
				return true;
			}
		}
	}
	return false;
}


glm::vec3 shade(objeto* objeto, glm::vec3 point, glm::vec3 normal, glm::vec3 eye, int  depth)
{
	glm::vec3 ambient_color = 0.4f*objeto->color;
	glm::vec3 color = ambient_color;
	float k = 1.f / ((float)lamps.size());

	for (int i = 0; i < (int)lamps.size(); i++)
	{
		glm::vec3 L = glm::normalize(lamps[i].position - point);
		if (glm::dot(normal, L) > 0.f) {
			if (!shadowed(point, lamps[i].position)) {

				color.r += lamps[i].color.r * k * glm::dot(normal, L);
				color.g += lamps[i].color.g * k * glm::dot(normal, L);
				color.b += lamps[i].color.b * k * glm::dot(normal, L);
				glm::vec3 r = 2.f * glm::dot(L, normal) * normal - L;
				r = glm::normalize(r);
				glm::vec3 v = eye - point;
				v = glm::normalize(v);
				color.r += lamps[i].color.r * k * pow(glm::dot(r, v), shininess);
				color.g += lamps[i].color.g * k * pow(glm::dot(r, v), shininess);
				color.b += lamps[i].color.b * k * pow(glm::dot(r, v), shininess);

			}
		}

		if (depth >= MAX_DEPTH) continue;

		if (objeto->getMaterial() == tipo::REFLETIVO) {
			color = 0.5f*ambient_color;
			glm::vec3 r = glm::normalize(eye - point);
			glm::vec3 rraio = 2.f * glm::dot(r, normal) * normal - r;
			rraio = glm::normalize(rraio);
			glm::vec3 rColor;
			raio the_raio;
			the_raio.position = point + normal;
			the_raio.direction = rraio;
			rColor = trace(the_raio, depth + 1);
			color += (0.5f*rColor);
		}
	}
	return color;
}


glm::vec3 trace(raio raio, int  depth)
{
	int max_distance = (int)camera.farp - (int)camera.nearp;
	glm::vec3 color = glm::vec3(1, 1, 1);

	float tmin;
	float tcurrentmin = camera.farp;
	for (int s = 0; s < (int)objetos.size(); s++)
	{
		glm::vec3 normal;
		if (objetos[s]->Hit(raio, tmin, normal))
		{
			if (depth == 1 && tmin > camera.nearp && tmin < camera.farp)
			{
				if (tmin < tcurrentmin)
				{
					tcurrentmin = tmin;
					glm::vec3 point = raio.position + tcurrentmin * raio.direction;
					color = shade(objetos[s], point, normal, raio.position, depth);
				}
			}
			else if (tmin > 0)
			{
				if (tmin < tcurrentmin)
				{
					tcurrentmin = tmin;
					glm::vec3 point = raio.position + tcurrentmin * raio.direction;
					color = shade(objetos[s], point, normal, raio.position, depth);
				}
			}
		}
	}
	return color;
}



void raio_tracer()
{
  for(int j = 0 ; j < height ; j++)
  {
    for(int i = 0 ; i < width ; i++)
    {
	  raio the_raio;
	  the_raio.position = camera.eye;
	  the_raio.direction = camera.vetorRaio((float)i, (float)j);
	  glm::vec3 pixel_color = trace(the_raio, 1);
      pixels[i*4 + j*width*4]     = pixel_color.r;
      pixels[i*4 + j*width*4 + 1] = pixel_color.g;
      pixels[i*4 + j*width*4 + 2] = pixel_color.b;
      pixels[i*4 + j*width*4 + 3] = 1.f;
    }
  }
}

static void Display (void)
{ 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glDrawPixels(width, height, GL_RGBA, GL_FLOAT, pixels);  

  glutSwapBuffers();
}

static void Idle(void)
{
  if(redisplay)
  {
	
	std::cout << "processando ...... por favor espere!" << std::endl;
	std::cout << "isto pode levar alguns segundos....... :)" << std::endl;
	raio_tracer();
	Display();
    redisplay = false;
	std::cout << "Ray Tracing ....... pipelina antigo do Opengl..... Pronto" << std::endl;
  }
 
}


void initGlew(){
	//abre a Glew e testa
	GLenum err = glewInit();
	if (GLEW_OK != err){
		fprintf(stderr, "ERRO NA GLEW: %s\n", glewGetErrorString(err));
		system("Pause");
		exit(-1);
	}
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);
  glutInitWindowSize(width, height);
  glutCreateWindow ("Ray Tracing");
  glutDisplayFunc(Display);
  glutIdleFunc(Idle);
  glutReshapeFunc(Reshape);
  initGlew();
  Init();
  glutMainLoop();

  return 0;
}