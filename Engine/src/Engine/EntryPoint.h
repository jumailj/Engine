#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();


int main(int argc, char *argv[]) 
{
	Engine::Log::Init();
	LOG_CORE_INFO("DIR: {0}", argv[0]);
	LOG_CORE_INFO("Welcome To Engine");
	LOG_INFO("Welcome to SandBox");

	Engine::Application *app = Engine::CreateApplication();
	app->Run();
	delete app;
}

#endif