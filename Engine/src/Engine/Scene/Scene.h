#pragma once

#include "entt.hpp"
#include "Engine/Core/Timestep.h"

namespace Engine {

	class Scene 
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		entt::registry& Reg() { return m_Registry; }

		void OnUpdate(Timestep ts);

	private:
			entt::registry m_Registry; // identifier-actual component data;

	};
}