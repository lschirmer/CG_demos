
#include "Camera.h"
static const float PI = 3.14159265359f;

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::camCreate(glm::vec3 _eye, glm::vec3 _at, glm::vec3 _up,float _fovy, float _nearp, float _farp,float w, float h)
{
	eye = _eye;
	center = _at;
	up = _up;

	fovy = _fovy;
	nearp = _nearp;
	farp = _farp;

	width = w;
	height = h;
	aspect = width / height;

	f = nearp;
	a = 2.0f * f * tan(((fovy / 2.0f) / 180.f)*PI);
	b = (width / height) * a;

	z_e = eye - center;
	z_e = glm::normalize(z_e);
	x_e = glm::cross(up, z_e);
	x_e = glm::normalize(x_e);
	y_e = glm::cross(z_e, x_e);
	y_e = glm::normalize(y_e);
}

glm::vec3 Camera::vetorRaio(float x, float y)
{
	glm::vec3 d =
		-(f * z_e)
		+ ((a * ((y / height) - (1.0f / 2.0f))) * y_e)
		+ ((b * ((x / width) - (1.0f / 2.0f))) * x_e);
	d = glm::normalize(d);
	return d;
}
