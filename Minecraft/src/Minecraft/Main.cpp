#include "MinecraftPCH.h"
#include "Application.h"

int main(int argc, char** argv)
{
	Minecraft::Log::Init();

	Minecraft::Application* app = new Minecraft::Application();
	app->Run();

	delete app;
}
