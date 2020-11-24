#include "pch.h"
#include "VertexArray.h"

bool nc::VertexArray::Create(const std::string& name, void* data)
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	return true;
}

void nc::VertexArray::Destory()
{
	glDeleteVertexArrays(m_count, &m_vao);
}

void nc::VertexArray::CreateBuffer(GLsizei size, GLsizei count, void* data)
{
	// set m_count to count;
	m_count = count;

	GLuint vbo = 0;
	// generate vertex buffer vbo with glGenBuffers
	glGenBuffers(1, &vbo);
	// bind vertex buffer glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// set buffer data glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

	// push back vbo onto m_vbos vector
	m_vbos.push_back(vbo);

}

void nc::VertexArray::SetAttribute(int index, GLint size, GLsizei stride, size_t offset)
{
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, (void*)(offset));
}

void nc::VertexArray::Draw(GLenum primitiveType)
{
	// bind vertex array m_vao with glBindVertexArray
	glBindVertexArray(m_vao);
	// call glDrawArrays with the parameters (primitive type, 0, m_count)
	glDrawArrays(primitiveType, 0, m_count);
}

