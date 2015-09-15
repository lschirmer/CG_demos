#include "objeto.h"


objeto::objeto(void)
{
}

objeto::~objeto(void)
{
	delete verts;
}

void objeto::setModelMatrix(glm::mat4 mat){
	m_modelMatrix = mat;
}

void objeto::setNormalMatrix(glm::mat4 view){
	m_normalMatrix = glm::inverseTranspose(view * m_modelMatrix);
}


glm::mat4 objeto::getModelMatrix(void){
	return m_modelMatrix;
}

glm::mat4 objeto::getNormalMatrix(void){
	return m_normalMatrix;
}

void objeto::setCores(float r, float g, float b){
	cores = new GLfloat[buff_size];
	for (int i = 0; i < buff_size; i += 3){
		cores[i] = r;
		cores[i + 1] = g;
		cores[i + 2] = b;
	}
	
}

void objeto::criabuff(){

	glGenVertexArrays(1,&vertexArrayID);
	glBindVertexArray(vertexArrayID);
	
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};

	
	
	glGenBuffers(1,&vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, buff_size*sizeof(verts), verts, GL_STATIC_DRAW);
	
	GLuint colorBuffer;
	glGenBuffers(1, &colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, buff_size*sizeof(cores), cores, GL_STATIC_DRAW);

	GLuint normal_buff;
	glGenBuffers(1, &normal_buff);
	glBindBuffer(GL_ARRAY_BUFFER, normal_buff);
    glBufferData(GL_ARRAY_BUFFER, buff_size*sizeof(normals), normals, GL_STATIC_DRAW);

	glGenBuffers(1, &indice_array);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indice_array);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*ind_tam, indices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
		);

	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
		);

	glBindBuffer(GL_ARRAY_BUFFER, normal_buff);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(
		2,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
		);
}

void objeto::Draw(){
	glBindVertexArray(vertexArrayID);
	glDrawElements(GL_TRIANGLES, ind_tam, GL_UNSIGNED_INT, NULL);
	glBindVertexArray(0);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	//glDisableVertexAttribArray(0);
}

grid::grid(int nx,int ny){
	this->nx = nx;
	this->ny = ny;
	ind_tam = (nx-1) * (ny-1) * 6;;
	size_t idx_size = (nx-1) * (ny-1) * 6;
	indices = new GLint[idx_size];
	buff_size = nx * ny *3;
	verts = new GLfloat[buff_size];
}

grid::~grid(){
}

void grid::criaGrid(){
   
   float step_x = static_cast<float>(1.f/nx);
   float step_y = static_cast<float>(1.f/ny);
   
   int k = 0;
   for(int i=0; i<nx;i++){
	 for(int j=0; j<ny;j++){
		 verts[k++] = static_cast<float>(i * step_x);
		 verts[k++] = static_cast<float>(j * step_y);
		 verts[k++] = 0.f;
	 }	
   }

   k = 0;
   for (int j = 0; j<ny-1 ; j++) {
	   for (int i = 0; i<nx-1 ; i++) {
		   indices[k++] = i * nx + j;
		   indices[k++] = (i + 1) * nx + j;
		   indices[k++] = i * nx + (j + 1);
		   indices[k++] = (i + 1) * nx + j;
		   indices[k++] = (i + 1) * nx + (j + 1);
		   indices[k++] = i * nx + (j + 1);
		   //std::cout << k << std::endl;
	   }
   }

   normals = new GLfloat[buff_size];
   int w = 0;
   for (int i = 0; i < buff_size; i+=3) {
	   normals[i] = 0;
	   normals[i+1] = 0;
	   normals[i+2] = -1;

   }
}

Sphere::Sphere(int slices, int stack){
	this->slices = slices;
	this->stack = stack;

	ind_tam = slices  * slices  * 6;;
	size_t idx_size = slices * slices  * 6;
	indices = new GLint[idx_size];
	
	buff_size = (slices) * (slices) * 3;
	verts = new GLfloat[buff_size];

}

Sphere::~Sphere(){

}

void Sphere::CriaSphere(){
  
  float h_step = static_cast<float>(2 * 3.14) / slices;
  float v_step = static_cast<float>(3.14) / slices;
  
  int idx = 0;
  for (float phi = 0; phi <= 3.14; phi += v_step) {
    for (float theta = 0; theta <= 2 * 3.14; theta += h_step) {
      verts[idx++] =  cos(theta) * sin(phi);
      verts[idx++] =  cos(phi);
      verts[idx++] =  sin(theta) * sin(phi);
    }
  }

  int k = 0;
  for (int j = 0; j<slices; j++) {
	  for (int i = 0; i<slices; i++) {
		  indices[k++] = i * slices + j;
		  indices[k++] = (i + 1) * slices + j;
		  indices[k++] = i * slices + (j + 1);
		  indices[k++] = (i + 1) * slices + j;
		  indices[k++] = (i + 1) * slices + (j + 1);
		  indices[k++] = i * slices + (j + 1);
		 // std::cout << k << std::endl;
	  }
  }

  normals = new GLfloat[buff_size];
  for (int i = 0; i < buff_size; i++){
	  normals[i] = verts[i];
  }

}
