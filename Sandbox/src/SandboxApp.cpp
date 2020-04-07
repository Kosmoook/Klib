#include <Klib.h>

class Sandbox : public Klib::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Klib::Application* Klib::CreateApplication()
{
	return new Sandbox();
}