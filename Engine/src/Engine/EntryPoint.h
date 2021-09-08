#pragma once
#include <iostream>

#ifdef ENGINE_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char *argv[]) 
{
	std::cout << "Welcome to Engine!" << std::endl;
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;


}


#endif