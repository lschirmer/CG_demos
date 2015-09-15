#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <glm/gtc/matrix_inverse.hpp>

class objeto
{

protected:
	GLuint vertexArrayID;
	GLuint indice_array;
	size_t buff_size;
	GLfloat *verts; 
	GLuint vertexbuffer;
	GLint *indices;
	GLfloat *cores;
	GLfloat *normals;
	int ind_tam;
	glm::mat4 m_modelMatrix;
	glm::mat4 m_normalMatrix;

public:
	objeto();
    ~objeto(void);
	void criabuff(void);
	void Draw(void);
	void setModelMatrix(glm::mat4 mat);
	void setNormalMatrix(glm::mat4 view);
	void setCores(float r, float g, float b);
	int index(int i, int j, int t);
	glm::mat4 getModelMatrix(void);
	glm::mat4 getNormalMatrix(void);
};

class grid : public objeto {

private:
	int nx,ny;

public:
	grid(int nx,int ny);
	~grid();
	void criaGrid();
};

class Sphere:public objeto{

private:
	int slices,stack;
public:
	Sphere(int slices,int stack);
	~Sphere(void);
	void CriaSphere(void);
};