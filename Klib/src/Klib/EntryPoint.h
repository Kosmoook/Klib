#pragma once

#ifdef KL_PLATFORM_WINDOWS

extern Klib::Application* Klib::CreateApplication();

int main(int argc, char** argv)
{
	Klib::Log::Init();

	auto app = Klib::CreateApplication();
	app->Run();
	delete app;
}


#endif