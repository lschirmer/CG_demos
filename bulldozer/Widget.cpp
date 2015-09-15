#include "Widget.h" 
#include <math.h>
#include "matriz.h"
#include "camera.h"


//aqui são implementadas as funções do canvas como pegar os pontos do canvas 1  e realizar o sweep no canvas 2



//desenha pontos no canvas 1
void MyCanvas::render(){


	 for(int i=0;i<count;i++){

		 circleFill(matp[i][0],matp[i][1],5,10);
		 
		 if(i>0){
			 
			 line(matp[i-1][0],matp[i-1][1],matp[i][0],matp[i][1]);

		 }
	 
	 }
	 
 }

 
void MyCanvas::update(){


}


void MyCanvas::onMouseClick(const scv::MouseEvent & evt){

	   if(count <100){
	     matp[count][0] = evt.getPosition().x;
	     matp[count][1] = evt.getPosition().y;
	     count ++;
	   }
}



void MyCanvas2::calcula_sweep(){

	float rads = 0;


	Matriz nova(4,4);

	nova.ortogonal();
    nova.escala(0.5);
    nova.translada3d(500,10,50);
	
	int k;
	mola = false;

	Matriz* auxiliar = novaCamera->M;
	for(int i=0; i<count;i++){
		 
		mVector3d* wow = new mVector3d((float)matp[i][0],(float)matp[i][1],50);
		k = 0;
		
		cout << matp[i][0] << " " << matp[i][1] << endl;
		
		rads = 0;
	 
		
		while(rads < 2*(6.28)){
          
		  mVector3d bla(0,0,0);
 		  Matriz aux(4,4); 
		  aux = nova;
		  aux.rotaciona3d_y(rads);
		  bla = aux * *wow; 		
		 

		 
		 //ortogonal ou perspectiva
		 
		 if(select == 1){
			 mats[i][k].x = (int)(bla.novamat[0][0]*2)/2;
		     mats[i][k].y = (int)((bla.novamat[1][0]*2)/2);

		 }
		 else{
		       bla.get_projection();
			   bla = *auxiliar * bla;//aplica câmera.
			   bla.homogeiniza();
		       mats[i][k].x = (int)(bla.novamat[0][0]*2)/5;
		       mats[i][k].y = (int)(bla.novamat[1][0]*2)/5;
		  }
		


		 
	
		 cout <<mats[i][k].x << " " << mats[i][k].y <<endl;
		  
		 rads+=(float)((3.14)/	8);
	
		 cout << "rads "<< rads << endl;
		 k++;
		}

	}

}


// realiza a translação e sweep para gerar a mola
void MyCanvas2::cria_mola(){

	float rads = 0;


	Matriz nova(4,4);

	nova.ortogonal();
    nova.escala(0.5);
    nova.translada3d(500,500,100);
	
	int k;
	float pass;
	
	for(int i=0; i<count;i++){
		 
		mVector3d* wow = new mVector3d((float)matp[i][0],(float)matp[i][1],50);
		k = 0;
		
		cout << matp[i][0] << " " << matp[i][1] << endl;
		
		rads = 0;
	 	pass = 0;
		
		while(rads < (2*6.28)){
          
		  mVector3d bla(0,0,0);
 		  Matriz aux(4,4); 
		  aux = nova;
		  aux.translada3d(0,-pass,0);
		  aux.rotaciona3d_y(rads);
		  bla = aux * *wow; 		

		  bla.get_projection();
		  mats[i][k].x = (int)(bla.novamat[0][0]*2)/5;
		  mats[i][k].y = (int)(bla.novamat[1][0]*2)/5;
		  cout <<mats[i][k].x << " " << mats[i][k].y <<endl;
		  
		  rads+=(float)((3.14)/8);
	      pass+=10;
		  cout << "rads "<< rads << endl;
		  k++;
		}

	}
}





void MyCanvas2::render(){


	for(int i=0;i<count;i++){
		
		for(int j=0;j<32;j++){

			circleFill(mats[i][j].x,mats[i][j].y,2,10);
	   		
			if(mola == false){ 
			  if((j+1 == 31)){
				line(mats[i][31].x,mats[i][31].y,mats[i][0].x,mats[i][0].y);
		      }
			}
			if(j+1 < 32){
                line(mats[i][j].x,mats[i][j].y,mats[i][j+1].x,mats[i][j+1].y);
			}
			
			if((i+1 < count)){
			  
			   line(mats[i][j].x,mats[i][j].y,mats[i+1][j].x,mats[i+1][j].y);
			   
			}			    
		}
	}
}


void MyCanvas2::update(){



}


// movimenta a câmera
void MyCanvas2::onKeyPressed(const scv::KeyEvent & evt)
{
	int key = atoi(evt.getKeyString().c_str());
   

   if (key == 'd') {
	   novaCamera->translate(-10,0,0);
   }
   
   if (key == 'a') {
	   novaCamera->translate(10,0,0);
   }

   if (key == 's') {
	   novaCamera->translate(0,-10,0);
   }
   if (key == 'w') {
	   novaCamera->translate(0,10,0);
   }
   if (key == 't') {
	   novaCamera->rotate(3,(float)0.151);
   }
   if (key == 'y') {
	   novaCamera->rotate(3,(float)-0.151);
   }
   if (key == 'g') {
	   novaCamera->rotate(2,(float)0.151);
   }
   if (key == 'h') {
	   novaCamera->rotate(2,(float)-0.151);
   }
   if (key == 'z') {
	   novaCamera->rotate(1,(float)0.151);
   }
   if (key == 'x') {
	   novaCamera->rotate(1,(float)-0.151);
   }
 

   if(mola==false){
      calcula_sweep();
   }
  

}



//pega os pontos para a figura com projeção ortogonal
void MyButton::onMouseClick(const scv::MouseEvent & evt){
		
	if(tf->count != 0){

		for(int i = 0;i<tf->count;i++){

			tg->matp[i][0] = tf->matp[i][0];
			tg->matp[i][1] = tf->matp[i][1];
				
		}
		
		tg->select = 1;
		tg->count = tf->count;
		tg->calcula_sweep();

	}
		

}

//pega os pontos para a figura com projeção em perspectiva
void MyButton2::onMouseClick(const scv::MouseEvent & evt){
		
	if(tf->count != 0){

		for(int i = 0;i<tf->count;i++){

			tg->matp[i][0] = tf->matp[i][0];
			tg->matp[i][1] = tf->matp[i][1];
				
		}
		
		tg->select = 2;
		tg->count = tf->count;
		tg->calcula_sweep();
		

	}
		

}


//pega os pontos para a mola
void MyButton3::onMouseClick(const scv::MouseEvent & evt){


	
	if(tf->count != 0){

		for(int i = 0;i<tf->count;i++){

			tg->matp[i][0] = tf->matp[i][0];
			tg->matp[i][1] = tf->matp[i][1];
				
		}
		tg->mola = true;
		tg->count = tf->count;
		tg->cria_mola();
	}

}


//reseta os pontos
void MyButton4::onMouseClick(const scv::MouseEvent & evt){

	memset(tf->matp,NULL,sizeof(tf->matp));
	memset(tg->matp,NULL,sizeof(tg->matp));
	tg->novaCamera = new Camera(new mVector3d(-10,-150,350), new mVector3d(-5,-150,-350), new mVector3d(0,1,0));
	tf->count = 0;
	tg->count = 0;
}

