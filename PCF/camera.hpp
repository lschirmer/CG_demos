#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <glm\glm.hpp>

void computeMatricesFromInputs();
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif