#pragma once

#include "pistao.h"
#include "braco1.h"
#include "../GL/glut.h"

//classe do segunda braço onde tem um soporte que liga ao resto da escavadeira.
class braco2{
public:
	braco2();
	~braco2();

	void desenha_braco2(float ang);
	void desenha_corpo();
	void suporte(); //suporte do pistao e omde se liga com o resto
};
