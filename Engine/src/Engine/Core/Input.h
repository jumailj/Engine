#pragma once

#include "Engine/Core/Core.h"
#include "Engine/Core/MouseCodes.h"
#include "Engine/Core/KeyCodes.h"

namespace Engine {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}