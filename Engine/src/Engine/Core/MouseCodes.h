#pragma once

namespace Engine
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode); 
		return os;
	}
}

#define EG_MOUSE_BUTTON_0      ::Engine::Mouse::Button0
#define EG_MOUSE_BUTTON_1      ::Engine::Mouse::Button1
#define EG_MOUSE_BUTTON_2      ::Engine::Mouse::Button2
#define EG_MOUSE_BUTTON_3      ::Engine::Mouse::Button3
#define EG_MOUSE_BUTTON_4      ::Engine::Mouse::Button4
#define EG_MOUSE_BUTTON_5      ::Engine::Mouse::Button5
#define EG_MOUSE_BUTTON_6      ::Engine::Mouse::Button6
#define EG_MOUSE_BUTTON_7      ::Engine::Mouse::Button7
#define EG_MOUSE_BUTTON_LAST   ::Engine::Mouse::ButtonLast
#define EG_MOUSE_BUTTON_LEFT   ::Engine::Mouse::ButtonLeft
#define EG_MOUSE_BUTTON_RIGHT  ::Engine::Mouse::ButtonRight
#define EG_MOUSE_BUTTON_MIDDLE ::Engine::Mouse::ButtonMiddle
