#pragma once

#include "Engine/Core/Layer.h"

#include <Engine/Events/ApplicationEvent.h>
#include <Engine/Events/KeyEvent.h>
#include <Engine/Events/MouseEvent.h>


namespace Engine {

	class ENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;
	//	virtual void OnImGuiRender() override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;

	};

}

