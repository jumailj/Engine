
namespace Engine {

	__declspec (dllexport) const char* show();
}

const char* Engine::show() {
	return "Welcome to Engine!";
}