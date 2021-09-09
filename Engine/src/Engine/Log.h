#pragma once
#include <memory>

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine {
	class ENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger>& GetClienLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

//core log macros;
#define LOG_ENGINE_CORE_TRACE(...)	::Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_ENGINE_CORE_INFO(...)	::Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_ENGINE_CORE_WARN(...)	::Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_ENGINE_CORE_ERROR(...)	::Engine::Log::GetCoreLogger()->error(__VA_ARGS__)

// clien log macros;
#define LOG_ERROR(...)::Engine::Log::GetClienLogger()->error(__VA_ARGS__)
#define LOG_WARN(...)::Engine::Log::GetClienLogger()->warn(__VA_ARGS__)
#define LOG_INFO(...)::Engine::Log::GetClienLogger()->info(__VA_ARGS__)
#define LOG_TRACE(...)::Engine::Log::GetClienLogger()->trace(__VA_ARGS__)

