#pragma once

#ifdef KL_PLATFORM_WINDOWS
	#ifdef KL_BUILD_DLL
		#define KLIB_API __declspec(dllexport)
	#else
		#define KLIB_API __declspec(dllimport)
	#endif // KL_BUILD_DLL
#else
	#error pouze winy!
#endif

#ifdef KL_ENABLE_ASSERTS
	#define KL_ASSERT(x, ...) { if(!(x)) { KL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define KL_CORE_ASSERT(x, ...) { if(!(x)) { KL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define KL_ASSERT(x, ...)
	#define KL_CORE_ASSERT(x, ...)
#endif

#define BIT(x)  (1 << x)