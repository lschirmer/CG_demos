#include "ThatShader.h"
#include <iostream>
#include <vector>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

ThatShader::ThatShader(void)
{
}


ThatShader::~ThatShader(void)
{
}


string ThatShader::abre(const char *path){
	string TheCode;
	ifstream Loader(path,ios::in);
	if(Loader.is_open())
    {
        std::string Line = "";
        while(getline(Loader, Line))
            TheCode += "\n" + Line;
		Loader.close();
    }
	return TheCode;
}

void ThatShader::init(const char *vertex,const char *frag){
	vertexShaderCode = abre(vertex);
	fragShaderCode = abre(frag);
}

void ThatShader::compile(){
	
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	cout << "compilando vertex shader"<< endl;
	cout << "-----------------"<< endl;

	Result = GL_FALSE;
    int InfoLogLength;
	//compila
	char const* source = vertexShaderCode.c_str();
	glShaderSource(vertexShaderID,1,&source,NULL);
	glCompileShader(vertexShaderID);
	// testa
	glGetShaderiv(vertexShaderID,GL_COMPILE_STATUS,&Result);
	glGetShaderiv(vertexShaderID,GL_INFO_LOG_LENGTH,&InfoLogLength);
	vector<char> justErrors(InfoLogLength);
	glGetShaderInfoLog(vertexShaderID,InfoLogLength,NULL,&justErrors[0]);
	fprintf(stdout,"%s\n", &justErrors[0]);

	cout << " compilando fragment shader"<<endl;
	cout << "--------------------------"<<endl;

	char const* fragSource = fragShaderCode.c_str();
	glShaderSource(fragShaderID,1,&fragSource,NULL);
	glCompileShader(fragShaderID);

	//testa frag
	glGetShaderiv(fragShaderID,GL_COMPILE_STATUS,&Result);
	glGetShaderiv(vertexShaderID,GL_INFO_LOG_LENGTH,&InfoLogLength);
	vector<char> ErrosFrag(InfoLogLength);
	glGetShaderInfoLog(fragShaderID,InfoLogLength,NULL,&ErrosFrag[0]);
	fprintf(stdout,"%s\n",&ErrosFrag[0]);

}

GLuint ThatShader::Linker(){
	
	int log;
	cout << " linking the Shader" << endl;
	programID = glCreateProgram();
	glAttachShader(programID,vertexShaderID);
	glAttachShader(programID,fragShaderID);
	glLinkProgram(programID);
	glGetProgramiv(programID,GL_LINK_STATUS,&Result);
	glGetProgramiv(programID,GL_INFO_LOG_LENGTH,&log);
	vector<char> erros(log);
	glGetProgramInfoLog(programID,log,NULL,&erros[0]);
	fprintf(stdout, "%s\n", &erros[0]);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragShaderID);
	return programID;
}

void ThatShader::Load(){
	glUseProgram(programID);
}

void ThatShader::unLoad(){
	glUseProgram(0);
}

GLuint ThatShader::GetLocation(GLuint ID, string go){
	return glGetUniformLocation(ID, go.c_str());
}

void ThatShader::UniformMatrix(GLuint ID, glm::mat4 that_Matrix){
	glUniformMatrix4fv(ID, 1, GL_FALSE, &that_Matrix[0][0]);
}

void ThatShader::Uniform1i(GLuint ID, int i){
	glUniform1i(ID,i);
}
void ThatShader::Uniform4fv(GLuint ID, glm::vec4 target){
	glUniform4fv(ID, 1, glm::value_ptr(target));
}

GLuint ThatShader::getProgramID(){
	return programID;
}