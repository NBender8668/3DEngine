#pragma once
#include "../Core/System.h"
#include "Resource.h"
namespace nc
{
	class ResourceManager : public System
	{
	public: 

		virtual bool Startup() override;
		virtual void Shutdown() override;
		virtual void Update() override;

		template<typename T>
		T* Get(const std::string& name, void* data = nullptr);

		void RemoveAll();
	
	protected:
		std::map<std::string, Resource*> m_resource;
	
	};
	template<typename T>
	inline T* ResourceManager::Get(const std::string& name, void* data)
	{
		T* resource = dynamic_cast<T*>(m_resource[name]);

		if (resource == nullptr)
		{
			resource = new T;
			resource->Create(name, data);

			m_resource[name] = resource;
		}

		return resource;
	}
}