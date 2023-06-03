#include <Engine.h>
#include <Engine/Core/EntryPoint.h>

#include "EditorLayer.h"
//#include "ExampleLayer.h"

namespace Engine {

	class EngineEditor : public Application
	{
	public:
		EngineEditor()
			:Application("ENGINE EDITOR")
		{
			// PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());

		}

		~EngineEditor()
		{

		}
	};

	Application* CreateApplication()
	{
		return new EngineEditor();
	}

}
