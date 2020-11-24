#pragma once
#include "../Resources/Resource.h"

namespace nc
{
	class Texture : public Resource
	{
	public:
		// Inherited via Resource
		virtual bool Create(const std::string& name, void* data = nullptr) override;
		virtual void Destory() override;
		
		bool CreateTexture(const std::string& filename, GLenum target = GL_TEXTURE_2D, GLuint unit = GL_TEXTURE0);

	protected:
		GLenum m_target{ GL_TEXTURE_2D };
		GLuint m_unit{ GL_TEXTURE0 };
		GLuint m_texture{ 0 };

	};
}
