#pragma once


#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

#define M_PI 3.14
#define M_PI2 6.28
#define GRAU_TO_RAD 0.017
#define RAD_TO_GRAU 57.29


class matriz{

public:
	matriz(int lin,int col);
	~matriz();

	float get(int lin,int col);
	void set(int lin,int col,float x); 
	void set_linha(int l,float a[], int tam);

	void operator +=(matriz& a);
	void operator -=(matriz& a);
	matriz operator + (matriz& a);
	matriz operator - (matriz& a);
	matriz operator * (matriz& a);

	matriz& matriz::operator = (matriz& a);

	void clear();

	void rotaciona2d(float ang);
	void translada(int tx,int ty);
	void escala(float s);

	void rotaciona3d(float ang,int x,int y,int z);
	void translada3d(int tx,int ty, int tz);
	void escala3d(float s);
	void perspectiva(int d);


protected:
	
	float mat[4][4];
	int linhas,cols;

};