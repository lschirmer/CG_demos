#pragma once

#include "carro.h"
#include "camera.h"
#include "../GL/glut.h"
#include "light.h"



//classe principal onde é chamada a escavadeira para desenho e a controla

class app{

public:

	static app* get_instance();


	inline static void teclado(unsigned char key, int x, int y){

		app::get_instance()->get_key((int)key);
	}

	app(int _posX, int _posY, int _sizeX, int _sizeY);
	~app();
	
	void get_key(int key);
	void run();
	static void render();
	void init();
	static int key;
	int posX, posY, sizeX, sizeY;  
	carro* car;
	cam *myCam;
	light *myLight; 
	
	int mykey;

private:
	static app* myinstance;

};
