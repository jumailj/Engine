#pragma once
#include "Core.h"

namespace Engine {

	 class ENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

	};

	 // to be define in CLIENT
	 Application* CreateApplication();

}
