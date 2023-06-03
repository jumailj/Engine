#include "EnginePCH.h"

#include "OrthographicCameraController.h"

#include "Engine/Core/Input.h"
#include "Engine/Core/KeyCodes.h"

namespace Engine {

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
		: m_AspectRatio(aspectRatio), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio* m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation)
	{
	}

	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		ENGINE_PROFILE_FUNCTION();
		
		if (Input::IsKeyPressed(EG_KEY_A))
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
		else if (Input::IsKeyPressed(EG_KEY_D))
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;

		if (Input::IsKeyPressed(EG_KEY_W))
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;
		else if (Input::IsKeyPressed(EG_KEY_S))
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;


		if (m_Rotation)
		{
			if (Input::IsKeyPressed(EG_KEY_Q)) {
				m_CameraRotation += m_CameraRotationSpeed * ts;
			}
				
			if (Input::IsKeyPressed(EG_KEY_E)) {
				m_CameraRotation -= m_CameraRotationSpeed * ts;
				LOG_CORE_INFO("CAMERA ROTATION: {0}", m_CameraRotation);
			}

			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CameraPosition);

		m_CameraTranslationSpeed = m_ZoomLevel;


		// mouse pan controller
	}


	void OrthographicCameraController::OnResize(float width, float height)
	{
		m_AspectRatio = width / height;
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}



	void OrthographicCameraController::OnEvent(Event& e)
	{
		ENGINE_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(ENGINE_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(ENGINE_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}

	void OrthographicCameraController::CalculateView()
	{
		m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		ENGINE_PROFILE_FUNCTION();

		m_ZoomLevel -= e.GetYOffset() * 0.25f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);

		CalculateView();
		
		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		ENGINE_PROFILE_FUNCTION();

		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		CalculateView();
		return false;
	}

}