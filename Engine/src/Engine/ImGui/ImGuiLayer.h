#pragma once

#include "Engine/Layer.h"


namespace Engine {

	class ENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		virtual void OnUpdate();
		virtual void OnEvent(Event& event);

	private:

		float m_Time = 0.0f;

	};

}