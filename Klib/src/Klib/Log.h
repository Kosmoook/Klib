#pragma once


#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"
namespace Klib {


	class KLIB_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;




	};

}


// core log macro
#define KL_CORE_TRACE(...)   ::Klib::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KL_CORE_INFO(...)    ::Klib::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KL_CORE_WARN(...)    ::Klib::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KL_CORE_ERROR(...)   ::Klib::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KL_CORE_FATAL(...)   ::Klib::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define KL_TRACE(...)        ::Klib::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KL_INFO(...)         ::Klib::Log::GetClientLogger()->info(__VA_ARGS__)
#define KL_WARN(...)         ::Klib::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KL_ERROR(...)        ::Klib::Log::GetClientLogger()->error(__VA_ARGS__)
#define KL_FATAL(...)        ::Klib::Log::GetClientLogger()->fatal(__VA_ARGS__)