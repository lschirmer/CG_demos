
#include "GL\glew.h"
#include "GL\glut.h"
#include "matriz.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

#pragma once


class cam{

public:

	matriz* position;
	
	float xgraus;
    float ygraus;
	
	float dxgraus;
	float dygraus;

	matriz* V; 
	matriz* U;
	matriz* W;

	cam();
	~cam();


	matriz* projeta(matriz* mat);
	void move_frente(float frente);
	void move_esq(float esq);
	void in_X(matriz* mat);
	void in_Y(matriz* mat);
	float* gera_rotate_cam();


private: 

	matriz* rotacao;
	matriz* multiplica;

	matriz* matrix;

	matriz* local;
	matriz* foco;
	matriz* top;
};