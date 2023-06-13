#pragma once

#include "glm/glm.hpp"

#include "Engine/Renderer/Camera.h"

namespace Engine {

	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {}
	};

	struct TransformComponent 
	{
		glm::mat4 Transfrom{ 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::mat4& transform)
			:Transfrom(transform) {}

		operator glm::mat4& () { return Transfrom; }
		operator const glm::mat4& () const { return Transfrom; }
	};


	struct SpriteRendererComponent
	{
		glm::vec4 Color{ 1.0f,1.0f, 1.0f,1.0f };

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4& color)
			:Color(color) {}

	};


	struct CameraComponent
	{
		Engine::Camera Camera;
		bool Primary = true; // todo move to scene;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
		CameraComponent(const glm::mat4& projection)
			:Camera(projection) {}

	};

}