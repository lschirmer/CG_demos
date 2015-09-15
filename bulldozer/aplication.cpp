
#include "aplication.h"

app* app::myinstance = NULL;


app* app::get_instance()
{
   if(myinstance)
      return myinstance;
   myinstance = new app(100,100,700,700);
   return myinstance;
}

app::app(int _posX, int _posY, int _sizeX, int _sizeY){
   posX = _posX;
   posY = _posY;
   sizeX = _sizeX; 
   sizeY = _sizeY;
   
 
   myLight = new light();
   myLight->setPosition(1000,250,1000);
   myLight->setAmbientColor(0.4,0.4,0.4);
   myLight->setDifuseColor(0.8,0.8,0.8);
  

   myCam = new cam();
   car = new carro(200,0,200);
}

app::~app(){
}



void app::get_key(int key){
	
	
	switch(key)
	{

	  case 97:
		  car->myRetro->decAngY();
		  break;
	  case 100:
		  car->myRetro->incAngY();
		  break;
	  case 119:
		  car->myRetro->incAngbraco2();
	      break;
	  case 115:
		  car->myRetro->decAngZbraco2();
		  break;
	  case 114:
		  car->myRetro->decAngbraco1();
		  break;
	  case 102:
		  car->myRetro->incAngZbraco1();
		  break;
	}

}

void app::render(){
   
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glClearColor(0, 0, 0, 1);
   
   glLoadIdentity();

   app* tmp = app::get_instance();
   
   tmp->myCam->setEscPos(tmp->car->getPosition(), tmp->car->getDirection());

   tmp->car->desenha();
   
   glutSwapBuffers();
}


void app::init(){

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(50, 1, 1, 1000);

   glMatrixMode(GL_MODELVIEW);  

   app::get_instance()->myLight->enable();
  
}

void app::run(){

   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize (sizeX, sizeY);
   glutInitWindowPosition (posX, posY);

   glutCreateWindow ("ola");
   init();
   
   glutDisplayFunc(render);
   glutKeyboardFunc(teclado);
   glutIdleFunc(render);

   glutMainLoop();
}