#pragma once

#include "glm/glm.hpp"

namespace Engine {

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


}