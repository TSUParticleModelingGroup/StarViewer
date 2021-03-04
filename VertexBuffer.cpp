#include "VertexBuffer.h"
#include "Renderer.h"
#include "Vertex.h"
#include <iostream>

VertexBuffer::VertexBuffer(unsigned int count, bool gpuInterop){
    m_count = count;
    glGenBuffers(1, &m_RendererID);
    //std::cout << "Vertex buffer creation: " <<  m_RendererID << std::endl;
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* 4 * count, nullptr, GL_DYNAMIC_DRAW);
}

VertexBuffer::~VertexBuffer(){
	glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::Bind() const{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::Unbind() const{
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
}

void VertexBuffer::Update(float * verticies) const{
    Bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, m_count*4*sizeof(float), verticies); //Warning 4 is hardcode for testing needs fixing
}
