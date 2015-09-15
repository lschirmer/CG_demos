#include "cam.h" 

cam::cam(){
	
	matrix = new matriz(4,4);

	multiplica = new matriz(4,4);

	position = new matriz(4,1);

	local = new matriz(4,1);
	local->set(0,0,0);
	local->set(1,0,50);
	local->set(2,0,-100);
	local->set(3,0,1);

	foco = new matriz(4,1);
	foco->set(0,0,0);
	foco->set(1,0,50);
	foco->set(2,0,1);
	foco->set(3,0,-99);

	top = new matriz(4,1);
	top->set(0,0,0);
	top->set(1,0,1);
	top->set(2,0,0);
	top->set(3,0,1);

	xgraus = 0.f;
	ygraus = 0.f;
	

	dxgraus = 0.f;
	dygraus = 0.f;
	

	rotacao = new matriz(4,4);
	rotacao->set(0,0,1);
	rotacao->set(1,1,1);
	rotacao->set(2,2,1);
	rotacao->set(3,3,1);

	position = new matriz(4,1);
	position = local;
	
	V = new matriz(4,1);
	V = top;
	V->normalize();

	W = new matriz(4,1);
	W->set(0,0,0); 
	W->set(1,0,0);
	W->set(2,0,foco->get(2,0) - local->get(2,0));
	W->normalize();
	
	U = new matriz(4,1); 
	U->cross(V,W); 
	U->normalize();
	V->cross(U,W);
	V->normalize();
	
	float bla = V->get(0,0);
	bla *= -1.f;
	V->set(0,0,bla);
	bla = V->get(1,0);
	bla*=-1.f;
	V->set(1,0,bla);
	bla = V->get(2,0);
	bla *=-1.f;
	V->set(2,0,bla);

	
}


cam::~cam(){

	delete this;
}



matriz* cam::projeta(matriz* mat){

	matriz * resp = new matriz (4,1);
	matriz bla(4,4);
	bla = *matrix;
	*resp = bla * *mat;
	resp->ortho(resp);
	return resp;
}


void cam::move_frente(float frente){

	position->translada3d(W->get(0,0)*frente*3,0,W->get(2,0)*frente*3);
	
}


void cam::move_esq(float esq){

	position->translada3d(U->get(0,0)*3*esq,0,U->get(2,0)*3*esq);
}




void cam::in_X(matriz* mat){

	     float angle = 0;

		 mat->set(1,0,1);
         multiplica = multiplica->rotate_eixo_arb(mat,-ygraus);
		 *rotacao = *multiplica * *rotacao;

		 *V = *multiplica * *V;
		 V->normalize();

		 *U = *multiplica * *U;
		 U->normalize();

		 *W = *multiplica * *W;
		 W->normalize();
		 

         mat->set(0,0,1);
         mat->set(1,0,0);
         mat->set(2,0,0);

         angle = dxgraus;
         xgraus += dxgraus;
         dxgraus = 0;
         
		
		 multiplica = multiplica->rotate_eixo_arb(mat,angle);
		 *rotacao = *multiplica * *rotacao;

		 *V = *multiplica * *V;
		 V->normalize();

		 *U = *multiplica * *U;
		 U->normalize();

		 *W = *multiplica * *W;
		 W->normalize();

         mat->set(0,0,0);
         mat->set(1,0,1);
         mat->set(2,0,0);
         
		 multiplica = multiplica->rotate_eixo_arb(mat,ygraus);
		 *rotacao = *multiplica * *rotacao;

		 *V = *multiplica * *V;
	     V->normalize();

	     *U = *multiplica * *U;
	     U->normalize();

	     *W = *multiplica * *W;
	     W->normalize();
}


void cam::in_Y(matriz* mat){

	float angle;

	mat->set(0,0,0);
    mat->set(1,0,1);
    mat->set(2,0,0);
    angle = dygraus;
    ygraus += dygraus;
    dygraus = 0;
    
	multiplica = multiplica->rotate_eixo_arb(mat,angle);
	*rotacao = *multiplica * *rotacao;

	*V = *multiplica * *V;
	V->normalize();

	*U = *multiplica * *U;
	U->normalize();

	*W = *multiplica * *W;
	W->normalize();
}

float* cam::gera_rotate_cam(){
	
	matriz* eixo = new matriz(3,1);


	if(dxgraus!=0){
		 
        in_X(eixo);
    }

	if( dygraus != 0 )
    {
        in_Y(eixo);
    }

	return rotacao->get_all();
}






