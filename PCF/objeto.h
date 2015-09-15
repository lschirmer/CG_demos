#pragma once
#include<vector>
#include<GL\glew.h>
#include<glm\glm.hpp>
#include"vboindexer.hpp"
#include"objloader.hpp"

class objeto
{

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	std::vector<unsigned short> indices;
	std::vector<glm::vec3> indexed_vertices;
	std::vector<glm::vec2> indexed_uvs;
	std::vector<glm::vec3> indexed_normals;
	bool res;
	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint elementbuffer;

public:
	objeto();
	~objeto();
	void LoadObjeto();
	void criabuff(void);
	void attribVertex(void);
	void attribColor(void);
	void attribNormal(void);
	void disableAvertex(void);
	void disableAnormal(void);
	void disableAcolor(void);
	void Draw(void);
};
