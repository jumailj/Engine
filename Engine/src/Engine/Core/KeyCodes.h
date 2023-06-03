#pragma once

namespace Engine
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define EG_KEY_SPACE           ::Engine::Key::Space
#define EG_KEY_APOSTROPHE      ::Engine::Key::Apostrophe    /* ' */
#define EG_KEY_COMMA           ::Engine::Key::Comma         /* , */
#define EG_KEY_MINUS           ::Engine::Key::Minus         /* - */
#define EG_KEY_PERIOD          ::Engine::Key::Period        /* . */
#define EG_KEY_SLASH           ::Engine::Key::Slash         /* / */
#define EG_KEY_0               ::Engine::Key::D0
#define EG_KEY_1               ::Engine::Key::D1
#define EG_KEY_2               ::Engine::Key::D2
#define EG_KEY_3               ::Engine::Key::D3
#define EG_KEY_4               ::Engine::Key::D4
#define EG_KEY_5               ::Engine::Key::D5
#define EG_KEY_6               ::Engine::Key::D6
#define EG_KEY_7               ::Engine::Key::D7
#define EG_KEY_8               ::Engine::Key::D8
#define EG_KEY_9               ::Engine::Key::D9
#define EG_KEY_SEMICOLON       ::Engine::Key::Semicolon     /* ; */
#define EG_KEY_EQUAL           ::Engine::Key::Equal         /* = */
#define EG_KEY_A               ::Engine::Key::A
#define EG_KEY_B               ::Engine::Key::B
#define EG_KEY_C               ::Engine::Key::C
#define EG_KEY_D               ::Engine::Key::D
#define EG_KEY_E               ::Engine::Key::E
#define EG_KEY_F               ::Engine::Key::F
#define EG_KEY_G               ::Engine::Key::G
#define EG_KEY_H               ::Engine::Key::H
#define EG_KEY_I               ::Engine::Key::I
#define EG_KEY_J               ::Engine::Key::J
#define EG_KEY_K               ::Engine::Key::K
#define EG_KEY_L               ::Engine::Key::L
#define EG_KEY_M               ::Engine::Key::M
#define EG_KEY_N               ::Engine::Key::N
#define EG_KEY_O               ::Engine::Key::O
#define EG_KEY_P               ::Engine::Key::P
#define EG_KEY_Q               ::Engine::Key::Q
#define EG_KEY_R               ::Engine::Key::R
#define EG_KEY_S               ::Engine::Key::S
#define EG_KEY_T               ::Engine::Key::T
#define EG_KEY_U               ::Engine::Key::U
#define EG_KEY_V               ::Engine::Key::V
#define EG_KEY_W               ::Engine::Key::W
#define EG_KEY_X               ::Engine::Key::X
#define EG_KEY_Y               ::Engine::Key::Y
#define EG_KEY_Z               ::Engine::Key::Z
#define EG_KEY_LEFT_BRACKET    ::Engine::Key::LeftBracket   /* [ */
#define EG_KEY_BACKSLASH       ::Engine::Key::Backslash     /* \ */
#define EG_KEY_RIGHT_BRACKET   ::Engine::Key::RightBracket  /* ] */
#define EG_KEY_GRAVE_ACCENT    ::Engine::Key::GraveAccent   /* ` */
#define EG_KEY_WORLD_1         ::Engine::Key::World1        /* non-US #1 */
#define EG_KEY_WORLD_2         ::Engine::Key::World2        /* non-US #2 */

/* Function keys */
#define EG_KEY_ESCAPE          ::Engine::Key::Escape
#define EG_KEY_ENTER           ::Engine::Key::Enter
#define EG_KEY_TAB             ::Engine::Key::Tab
#define EG_KEY_BACKSPACE       ::Engine::Key::Backspace
#define EG_KEY_INSERT          ::Engine::Key::Insert
#define EG_KEY_DELETE          ::Engine::Key::Delete
#define EG_KEY_RIGHT           ::Engine::Key::Right
#define EG_KEY_LEFT            ::Engine::Key::Left
#define EG_KEY_DOWN            ::Engine::Key::Down
#define EG_KEY_UP              ::Engine::Key::Up
#define EG_KEY_PAGE_UP         ::Engine::Key::PageUp
#define EG_KEY_PAGE_DOWN       ::Engine::Key::PageDown
#define EG_KEY_HOME            ::Engine::Key::Home
#define EG_KEY_END             ::Engine::Key::End
#define EG_KEY_CAPS_LOCK       ::Engine::Key::CapsLock
#define EG_KEY_SCROLL_LOCK     ::Engine::Key::ScrollLock
#define EG_KEY_NUM_LOCK        ::Engine::Key::NumLock
#define EG_KEY_PRINT_SCREEN    ::Engine::Key::PrintScreen
#define EG_KEY_PAUSE           ::Engine::Key::Pause
#define EG_KEY_F1              ::Engine::Key::F1
#define EG_KEY_F2              ::Engine::Key::F2
#define EG_KEY_F3              ::Engine::Key::F3
#define EG_KEY_F4              ::Engine::Key::F4
#define EG_KEY_F5              ::Engine::Key::F5
#define EG_KEY_F6              ::Engine::Key::F6
#define EG_KEY_F7              ::Engine::Key::F7
#define EG_KEY_F8              ::Engine::Key::F8
#define EG_KEY_F9              ::Engine::Key::F9
#define EG_KEY_F10             ::Engine::Key::F10
#define EG_KEY_F11             ::Engine::Key::F11
#define EG_KEY_F12             ::Engine::Key::F12
#define EG_KEY_F13             ::Engine::Key::F13
#define EG_KEY_F14             ::Engine::Key::F14
#define EG_KEY_F15             ::Engine::Key::F15
#define EG_KEY_F16             ::Engine::Key::F16
#define EG_KEY_F17             ::Engine::Key::F17
#define EG_KEY_F18             ::Engine::Key::F18
#define EG_KEY_F19             ::Engine::Key::F19
#define EG_KEY_F20             ::Engine::Key::F20
#define EG_KEY_F21             ::Engine::Key::F21
#define EG_KEY_F22             ::Engine::Key::F22
#define EG_KEY_F23             ::Engine::Key::F23
#define EG_KEY_F24             ::Engine::Key::F24
#define EG_KEY_F25             ::Engine::Key::F25

/* Keypad */
#define EG_KEY_KP_0            ::Engine::Key::KP0
#define EG_KEY_KP_1            ::Engine::Key::KP1
#define EG_KEY_KP_2            ::Engine::Key::KP2
#define EG_KEY_KP_3            ::Engine::Key::KP3
#define EG_KEY_KP_4            ::Engine::Key::KP4
#define EG_KEY_KP_5            ::Engine::Key::KP5
#define EG_KEY_KP_6            ::Engine::Key::KP6
#define EG_KEY_KP_7            ::Engine::Key::KP7
#define EG_KEY_KP_8            ::Engine::Key::KP8
#define EG_KEY_KP_9            ::Engine::Key::KP9
#define EG_KEY_KP_DECIMAL      ::Engine::Key::KPDecimal
#define EG_KEY_KP_DIVIDE       ::Engine::Key::KPDivide
#define EG_KEY_KP_MULTIPLY     ::Engine::Key::KPMultiply
#define EG_KEY_KP_SUBTRACT     ::Engine::Key::KPSubtract
#define EG_KEY_KP_ADD          ::Engine::Key::KPAdd
#define EG_KEY_KP_ENTER        ::Engine::Key::KPEnter
#define EG_KEY_KP_EQUAL        ::Engine::Key::KPEqual

#define EG_KEY_LEFT_SHIFT      ::Engine::Key::LeftShift
#define EG_KEY_LEFT_CONTROL    ::Engine::Key::LeftControl
#define EG_KEY_LEFT_ALT        ::Engine::Key::LeftAlt
#define EG_KEY_LEFT_SUPER      ::Engine::Key::LeftSuper
#define EG_KEY_RIGHT_SHIFT     ::Engine::Key::RightShift
#define EG_KEY_RIGHT_CONTROL   ::Engine::Key::RightControl
#define EG_KEY_RIGHT_ALT       ::Engine::Key::RightAlt
#define EG_KEY_RIGHT_SUPER     ::Engine::Key::RightSuper
#define EG_KEY_MENU            ::Engine::Key::Menu