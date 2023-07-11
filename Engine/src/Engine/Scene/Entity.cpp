#include "EnginePCH.h"
#include "Entity.h"


namespace Engine {


	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}
}