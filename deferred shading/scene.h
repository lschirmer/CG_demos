#pragma once
#include <GL/glew.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <iostream>
#include <glm/gtc/matrix_inverse.hpp>
class scene
{

private:
	GLuint scenebuff;
	GLuint buffv;
	GLuint bufft;
	GLuint buffind;
	glm::vec4 material;
	glm::mat4 m_modelMatrix, m_normalMatrix;
public:
	scene();
	~scene();
	void quad_gen(void);
	void bind(void);
	void draw(void);
	void setModelMatrix(glm::mat4 mat);
	glm::mat4 getModelMatrix(void);
	void setNormalMatrix(glm::mat4 mat);
	glm::mat4 getNormalMatrix(void);
	glm::vec4 getMaterial(void);
};

