#include "objeto.h"




objeto::objeto(){
}

objeto::objeto(geometria the_tipo)
{
	type = the_tipo;
}

objeto::~objeto(){

}

geometria objeto::getType()
{
	return type;
}

void objeto::setType(geometria _type)
{
	type = _type;
}

tipo objeto::getMaterial()
{
	return material;
}

void objeto::setMaterial(tipo _material)
{
	material = _material;
}

esfera::esfera(){};

esfera::esfera(glm::vec3 _position, float _radius, glm::vec3 _color): objeto(geometria::SPHERE)
{
	center = _position;
	the_raio = _radius;
	color = _color;
	slices = 50;
	stacks = 50;
}

esfera::~esfera()
{
}

bool esfera::Hit(raio ray, float &tmin, glm::vec3 &normalv)
{
	float a = glm::dot(ray.direction, ray.direction);
	float b = glm::dot(2.0f * ray.direction, ray.position - center);
	float c = glm::dot(ray.position - center, ray.position - center) - (the_raio* the_raio);

	float delta = b * b - 4.0f * a * c;
	if (delta > 0.0f)
	{
		float t1 = (-b - sqrt(delta)) / (2.f * a);
		float t2 = (-b + sqrt(delta)) / (2.f * a);
		tmin = std::min(t1, t2);
		normalv = normal(ray.position + tmin*ray.direction);
		return true;
	}
	return false;
}

void esfera::draw()
{
	glColor3f(color.r, color.g, color.b);
	glPushMatrix();
	glTranslatef(center.x, center.y, center.z);
	glutSolidSphere(the_raio, slices, stacks);
	glPopMatrix();
}

glm::vec3 esfera::normal(glm::vec3 point)
{
	return glm::normalize(point - center);
}

espelho::espelho(glm::vec3 posmin, glm::vec3 posmax, glm::vec3 cor)
: objeto(geometria::BOX)
{
	p_min = posmin;
	p_max = posmax;
	color = cor;
}

espelho::espelho(){

}

espelho::~espelho()
{
}


bool espelho::Hit(raio ray, float &tmin, glm::vec3 &normalv)
{
	float x0 = p_min.x; float y0 = p_min.y; float z0 = p_min.z;
	float x1 = p_max.x; float y1 = p_max.y; float z1 = p_max.z;

	float ox = ray.position.x;  float oy = ray.position.y;  float oz = ray.position.z;
	float dx = ray.direction.x; float dy = ray.direction.y; float dz = ray.direction.z;

	float tx_min, ty_min, tz_min;
	float tx_max, ty_max, tz_max;

	float a = 1.0f / dx;
	if (a >= 0.0f)
	{
		tx_min = (x0 - ox) * a;
		tx_max = (x1 - ox) * a;
	}
	else
	{
		tx_min = (x1 - ox) * a;
		tx_max = (x0 - ox) * a;
	}

	float b = 1.0f / dy;
	if (b >= 0.0f)
	{
		ty_min = (y0 - oy) * b;
		ty_max = (y1 - oy) * b;
	}
	else
	{
		ty_min = (y1 - oy) * b;
		ty_max = (y0 - oy) * b;
	}

	float c = 1.0f / dz;
	if (c >= 0.0f)
	{
		tz_min = (z0 - oz) * c;
		tz_max = (z1 - oz) * c;
	}
	else
	{
		tz_min = (z1 - oz) * c;
		tz_max = (z0 - oz) * c;
	}

	float kEpsilon = 0.0f;
	int face_in, face_out;
	float t0, t1;

	if (tx_min > ty_min){
		t0 = tx_min;
		face_in = (a >= 0.0f) ? 0 : 3;
	}
	else{
		t0 = ty_min;
		face_in = (b >= 0.0f) ? 1 : 4;
	}
	if (tz_min > t0){
		t0 = tz_min;
		face_in = (c >= 0.0f) ? 2 : 5;
	}

	if (tx_max < ty_max){
		t1 = tx_max;
		face_out = (a >= 0.0f) ? 3 : 0;
	}
	else{
		t1 = ty_max;
		face_out = (b >= 0.0f) ? 4 : 1;
	}

	if (tz_max < t1){
		t1 = tz_max;
		face_out = (c >= 0.0f) ? 5 : 2;
	}

	if (t0 < t1 && t1 > kEpsilon)
	{
		if (t0 > kEpsilon)
		{
			tmin = t0;
			normalv = normal(face_in);
		}
		else
		{
			tmin = t1;
			normalv = normal(face_out);
		}
		return true;
	}
	else
	{
		return false;
	}
}

void espelho::draw()
{
	glColor3f(color.r, color.g, color.b);
	glPushMatrix();


	glTranslatef((p_min.x + p_max.x) / 2.f,
		(p_min.y + p_max.y) / 2.f,
		(p_min.z + p_max.z) / 2.f);

	glutSolidCube(60);

	glPopMatrix();
}

glm::vec3 espelho::normal(glm::vec3 point)
{
	return glm::vec3(0, 0, 0);
}

glm::vec3 espelho::normal(int face_hit)
{
	switch (face_hit)
	{
	case 0: return glm::vec3(-1.f, 0.f, 0.f);
	case 1: return glm::vec3(0.f, -1.f, 0.f);
	case 2: return glm::vec3(0.f, 0.f, -1.f);
	case 3: return glm::vec3(1.f, 0.f, 0.f);
	case 4: return glm::vec3(0.f, 1.f, 0.f);
	case 5: return glm::vec3(0.f, 0.f, 1.f);
	default: return glm::vec3(0.f, 0.f, 0.f);
	}
}

luz::luz(){}


luz::luz(glm::vec3 position, glm::vec3 cor)
: objeto(geometria::LIGHT)
{
	position = position;
	color = cor;
	radius = 10;
	slices = 20;
	stacks = 20;
}


luz::~luz()
{
}


bool luz::Hit(raio ray, float &tmin, glm::vec3 &normal)
{
	return false;

}

void luz::draw()
{
	glColor3f(color.r, color.g, color.b);
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(radius, slices, stacks);
	glPopMatrix();
}

glm::vec3 luz::normal(glm::vec3 point)
{
	return glm::normalize(position - point);
}