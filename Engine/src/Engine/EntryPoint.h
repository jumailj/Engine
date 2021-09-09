#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();


int main(int argc, char *argv[]) 
{
	Engine::Log::Init();
	LOG_ENGINE_CORE_INFO("Welcome To Engine");
	LOG_INFO("Welcome to the Engine-editor");

	Engine::Application *app = Engine::CreateApplication();
	app->Run();
	delete app;
}

#endif