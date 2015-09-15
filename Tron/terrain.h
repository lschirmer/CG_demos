

#include <stdio.h>
#include<iostream>
#include <Windows.h>
#include <math.h>
#include "../GL/glew.h"

#include "../GL/gl.h"
#include "../GL/glext.h"



#define area 4
#define escale 10

#pragma comment(lib,"glew32.lib")

using namespace std;


class vert{

public:	
	float x;
	float y;
	float z;

};


class terrain{


private:
	int l_height;
	int l_widht;

	int x_max;
	int x_min;
	int z_max;
	int z_min;
	int lod;
	int vertex_count;
	int local;
	
	int x_tmax,x_tmin,z_tmax,z_tmin;
	
	vert* vertices;
	

	unsigned int VBOvertices;


	bool Init(void);

	void lines();
public:	
	
	terrain();
	~terrain();
	bool load(char* name,int width,int height);
	float dist(float c_x,float c_z,float g_x,float g_z);
	void segment(float c_x,float c_z);
	void new_segment(void);
	void transition(void);
	void render_tarea(void);
	void render_tarea1(void);
	void render_tarea2(void);
	void render(float c_x,float c_z);
	
	unsigned char the_grid[513][513];


};
