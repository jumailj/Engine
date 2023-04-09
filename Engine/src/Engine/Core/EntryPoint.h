#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();


int main(int argc, char *argv[]) 
{
	Engine::Log::Init();
	LOG_CORE_INFO("DIR: {0}", argv[0]);

	ENGINE_PROFILE_BEGIN_SESSION("STARTUP", "ENGINEPROFILE-STARUP.json");
	Engine::Application *app = Engine::CreateApplication();
	ENGINE_PROFILE_END_SESSION();

	ENGINE_PROFILE_BEGIN_SESSION("RUNTIME", "ENGINEPROFILE-RUNTIME.json");
	app->Run();
	ENGINE_PROFILE_END_SESSION();

	ENGINE_PROFILE_BEGIN_SESSION("SHUTDOWN", "ENGINEPROFILE-SHUTDOWN.json");
	delete app;
	ENGINE_PROFILE_END_SESSION();
}

#endif