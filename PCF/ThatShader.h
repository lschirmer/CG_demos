#pragma once
#include <string>
#include <GL/glew.h>
#include <fstream>
#include <string>
#include <glm/glm.hpp>

using namespace std;

class ThatShader
{

private: 
	GLuint programID;
	string fragShaderCode;
	string vertexShaderCode; 
	GLuint vertexShaderID,fragShaderID;
	GLint Result;
public:
	ThatShader(void);
	~ThatShader(void);
	GLuint getProgramID();
	void init(const char* vertex, const char* frag);
	string abre(const char* path);
	void compile(void);
	GLuint Linker(void);
	GLuint GetLocation(GLuint ID, string go);
	void UniformMatrix(GLuint ID, glm::mat4 that_Matrix);
	void Uniform3f(GLuint ID, glm::vec3 vec);
	void Uniform(GLuint ID, int a);
	void Load(void);
	void unLoad(void);
};

