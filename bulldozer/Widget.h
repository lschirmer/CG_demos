#ifndef __WIDGET_H__
#define __WIDGET_H__

#include <SCV/SCV.h>
#include <string>
#include "matriz.h"
#include "camera.h"




//Aqui são declaradas as classes canvas e dos bostões

class MyCanvas : public scv::Canvas

{
  public:

   int count;
   int x,y;
   
  
   int matp[100][2];
   
 
   
   MyCanvas() : scv::Canvas(scv::Point(119,74), scv::Point(525, 663)){
	   
      count = 0; 
	  x = 0;
	  y = 0;
	
   }

   void render();

  // void projeta();

   void update();

   void onMouseClick(const scv::MouseEvent &evt);


private:
   static const int RECT_SIZE = 8;
   static const int TRIANGLE_SIZE = 16;

   // Posicao atual dos triangulos
   scv::Point pos;
   // Velocidade atual dos triangulos
   scv::Point cur_speed;
   // Cor do fundo
   scv::Color4f bg_color;

};




class MyCanvas2 : public scv::Canvas

{
  public:

   int count;
   int x,y;
   
  
   int matp[100][2];
   scv::Point mats[100][32]; 
   int select;
   bool mola;
   Camera* novaCamera;
   
   MyCanvas2() : scv::Canvas(scv::Point(534,74), scv::Point(1007, 662)){
	   
      count = 0; 
	  x = 0;
	  y = 0;
	  mola = false;
	  novaCamera = new Camera(new mVector3d(-10,-150,350), new mVector3d(5,150,-350), new mVector3d(0,1,0));
   }

  
  void calcula_sweep();

  void cria_mola();

  void render();

  // void projeta();

  void update();
 
  void onKeyPressed(const scv::KeyEvent & evt);

private:
   static const int RECT_SIZE = 8;
   static const int TRIANGLE_SIZE = 16;

   // Posicao atual dos triangulos
   scv::Point pos;
   // Velocidade atual dos triangulos
   scv::Point cur_speed;
   // Cor do fundo
   scv::Color4f bg_color;

};





class MyButton : public scv::Button {
public:
	
	
	MyButton(scv::Point p1, scv::Point p2, MyCanvas* tf,MyCanvas2* tg)
      : scv::Button(p1, p2, " proj. ortogonal"),tf(tf),tg(tg)
   {
   
   }

  
   
   //int matriz[100][2];

  
  void onMouseClick(const scv::MouseEvent &evt);
 
   


private:
   MyCanvas *tf;
   MyCanvas2 *tg;
  
};


class MyButton2 : public scv::Button {
public:
	
	
	MyButton2(scv::Point p1, scv::Point p2, MyCanvas* tf,MyCanvas2* tg)
      : scv::Button(p1, p2, "proj. perspectiva"),tf(tf),tg(tg)
   {
   }

  
   
   //int matriz[100][2];

  
  void onMouseClick(const scv::MouseEvent &evt);
 
   


private:
   MyCanvas *tf;
   MyCanvas2 *tg;
  
};


class MyButton3 : public scv::Button {
public:
	
	
	MyButton3(scv::Point p1, scv::Point p2, MyCanvas* tf,MyCanvas2* tg)
      : scv::Button(p1, p2, "desenha mola"),tf(tf),tg(tg)
   {
   }

  
   
   //int matriz[100][2];

  
  void onMouseClick(const scv::MouseEvent &evt);
 
   


private:
   MyCanvas *tf;
   MyCanvas2 *tg;
  
};



class MyButton4 : public scv::Button {
public:
	
	
	MyButton4(scv::Point p1, scv::Point p2, MyCanvas* tf,MyCanvas2* tg)
      : scv::Button(p1, p2, "Resetar"),tf(tf),tg(tg)
   {
   }

  
   
  

  
  void onMouseClick(const scv::MouseEvent &evt);
 
   


private:
   MyCanvas *tf;
   MyCanvas2 *tg;
  
};


#endif