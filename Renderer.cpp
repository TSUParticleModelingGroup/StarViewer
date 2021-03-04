#include "Renderer.h"
#include <iostream>

void Renderer::Clear() const{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader, const GLenum& TYPEOFDRAW) const{
	shader.Bind();
	va.Bind();
	ib.Bind();
	if(TYPEOFDRAW == GL_POINTS){
		glPointSize(1.0f);	
	}else if(TYPEOFDRAW == GL_LINE){
		glLineWidth(3.0f);
	}
	//std::cout << "Drawing Particles:" << std::endl;
	glDrawElements(TYPEOFDRAW, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(Grid& grid){
	while(glGetError() != GL_NO_ERROR);
	grid.Bind();
	int count = grid.getIBCount();
	//std::cout << "Drawing Grid" << std::endl;
	glDrawElements(GL_LINES, count, GL_UNSIGNED_INT, nullptr);
	while(GLenum error = glGetError()){
		std::cout << "[OpenGL error] :" <<  error << std::endl;
	}
}
