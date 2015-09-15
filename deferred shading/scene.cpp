#include "scene.h"


scene::scene()
{
}


scene::~scene()
{
}


void scene::setModelMatrix(glm::mat4 mat){
	m_modelMatrix = mat;
}

void scene::setNormalMatrix(glm::mat4 view){
	m_normalMatrix = glm::inverseTranspose(view * m_modelMatrix);
}


glm::mat4 scene::getModelMatrix(void){
	return m_modelMatrix;
}

glm::mat4 scene::getNormalMatrix(void){
	return m_normalMatrix;
}


void scene::quad_gen(){


	GLfloat vertices[] = {
		-1, -1, 0,
		1, -1, 0,
		1, 1, 0,
		-1, 1, 0
	};

	GLfloat texCoord[] = {
		0, 0,
		1, 0,
		1, 1,
		0, 1
	};

	GLubyte indices[] = {
		1, 2, 0, 3
	};

	glGenVertexArrays(1, &scenebuff);

	glGenBuffers(1, &buffv);
	glBindBuffer(GL_ARRAY_BUFFER, buffv);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* 12, vertices, GL_STATIC_DRAW);
	
	glGenBuffers(1, &bufft);
	glBindBuffer(GL_ARRAY_BUFFER, bufft);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)* 8, texCoord, GL_STATIC_DRAW);

	glBindVertexArray(scenebuff);

	glGenBuffers(1, &buffind);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffind);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte)* 4, indices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, buffv);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3, GL_FLOAT,GL_FALSE,0,NULL);

	glBindBuffer(GL_ARRAY_BUFFER, bufft);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	//glBindVertexArray(0);


}

void scene::bind(){

	glBindVertexArray(scenebuff);
}

void scene::draw(){
	glDrawElements(GL_TRIANGLE_STRIP, sizeof(GLfloat)* 4, GL_UNSIGNED_BYTE, NULL);
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}

glm::vec4 scene::getMaterial(){
	return material;
}