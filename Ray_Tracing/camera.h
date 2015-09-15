#ifndef ___CAMERA__LQC__H___
#define ___CAMERA__LQC__H___

#include <glm/glm.hpp>

class Camera
{
public:
	Camera();
	~Camera();

	void camCreate(glm::vec3 eye, glm::vec3 at, glm::vec3 up,float fovy, float nearp, float farp, float w, float h);

	glm::vec3 vetorRaio(float x, float y);
	glm::vec3 eye, center, up;
	float nearp, farp,fovy,aspect;
	glm::vec3 x_e, y_e, z_e;
private:
	float width, height;
	float f, a, b;
};

#endif