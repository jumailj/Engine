#include <iostream>

namespace Engine {
	__declspec (dllimport) const char* show();
}


int main() {

	std::cout << Engine::show() << std::endl;

}