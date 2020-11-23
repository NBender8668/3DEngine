#pragma once
#include "Resource.h"
#include "Audio/AudioChannel.h"
#include <fmod.hpp>

namespace nc
{
	class Sound : public  Resource
	{
	public:
		 
		virtual bool Create(const std::string name, void* audiosystem) override;

		virtual void Destory() override;

		AudioChannel Play(bool loop = false);

	private:
		FMOD::System* m_system{ nullptr };
		FMOD::Sound* m_sound{ nullptr };

	
	};
}
