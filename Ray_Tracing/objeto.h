#pragma once
#include <glm/glm.hpp>
#include <GL\glew.h>
#include <GL\glut.h>
#include<algorithm>


typedef struct raio{
	glm::vec3 position, direction;
}raio;

enum tipo{DEFAULT, REFLETIVO};
enum geometria{ SPHERE, BOX, LIGHT};


class objeto
{
public:
	objeto();
	objeto(geometria the_tipo);
	~objeto();
	virtual bool Hit(raio ray, float &tmin, glm::vec3 &normal) = 0;
	virtual void draw() = 0;
	virtual glm::vec3 normal(glm::vec3 point) = 0;

	geometria getType();
	tipo getMaterial();
	void setType(geometria type);
	void setMaterial(tipo material);

	glm::vec3 color;
private:
	geometria type;
	tipo material;
};


class espelho:public objeto{
public:
	espelho();
	espelho(glm::vec3 posmin,glm::vec3 posmax,glm::vec3 cor);
	~espelho();

	void ciar();

	virtual bool Hit(raio ray, float &tmin, glm::vec3 &normal);
	virtual void draw();
	virtual glm::vec3 normal(glm::vec3 point);
	glm::vec3 normal(int face_hit);

private:
	glm::vec3 p_min, p_max;
};

class esfera:public objeto{
public:	
	esfera();
	esfera(glm::vec3 position,float raio,glm::vec3 cor);
	~esfera();

	virtual bool Hit(raio ray, float &tmin, glm::vec3 &normal);
	virtual void draw();
	virtual glm::vec3 normal(glm::vec3 point);

private:
	glm::vec3 center;
	float the_raio;
	int slices, stacks;
};

class luz :public objeto{
public:
	luz();
	luz(glm::vec3 position, glm::vec3 cor);
	~luz();

	void lightCreate();

	virtual bool Hit(raio ray, float &tmin, glm::vec3 &normal);
	virtual void draw();
	virtual glm::vec3 normal(glm::vec3 point);
	glm::vec3 position;

private:
	float radius, slices, stacks;
};
