#include "EnginePCH.h"
#include "Scene.h"

#include "Components.h"
#include "Engine/Renderer/Renderer2D.h"
#include "glm/glm.hpp"

namespace Engine {

	static void DoMath(const glm::mat4& transfrom){}

	static void OnTransformConstruct(entt::registry& registry, entt::entity entity) {}

	Scene::Scene()
	{
		struct MeshComponent {
			bool wokring = true;
			MeshComponent() = default;

		};

		struct TransfromComponent
		{
			glm::mat4 Transform;

			TransfromComponent() = default;
			TransfromComponent(const TransfromComponent&) = default;

			TransfromComponent(const glm::mat4& transfrom)  //copy constructor;
				:Transform(transfrom) {}
			// no default destructor;

			operator glm::mat4& () { return Transform; } // Transfrom.transfrom;
			operator const glm::mat4& ()const { return Transform; }

		};

		//TransfromComponent transform;
		//DoMath(transform); // operator overloading;

#if ENTT_EXAMPLE

		entt::entity entity = m_Registry.create(); //uint32_t
		m_Registry.emplace<TransfromComponent>(entity, glm::mat4(1.0f)); // explict constructor

		m_Registry.on_construct<TransfromComponent>().connect<&OnTransformConstruct>();

		
		auto view = m_Registry.view<TransfromComponent>();

		for (auto entity: view) {
			TransfromComponent& transfrom = view.get<TransfromComponent>(entity);
		}

		auto group = m_Registry.group<TransfromComponent>(entt::get<MeshComponent>);
		for (auto entity : group) {

//			auto&[transfrom, mesh] = group.get<TransfromComponent, MeshComponent>(entity);
//			Renderer::submit(mesh, transfrom);
		}
#endif

	}

	Scene::~Scene()
	{

	}

	entt::entity Scene::CreateEntity()
	{
		return m_Registry.create();
	}

	void Scene::OnUpdate(Timestep ts) {

		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group)
		{
			auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

			Renderer2D::DrawQuad(transform, sprite.Color);

		}
	}
}