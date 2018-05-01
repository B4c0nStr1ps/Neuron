#include "application.h"
#include "core\filesystem.h"

namespace neuron {

Application::Application(const char* executable_path)
{
	//Get the executable relative folder.
	app_directory_ = filesystem::GetFolderFromPath(executable_path);
	//Get the executable name.
	app_name_ = filesystem::GetFilenameFromPath(executable_path);
	//Get the application data folder.
	data_directory_rel_ = filesystem::CombinePaths("\\", app_name_ + "_data");
}

Application::~Application()
{
}

NString Application::Name()
{
	return app_name_;
}

NString Application::DataDirectory()
{
	return data_directory_rel_;
}

NString Application::AppDirectory()
{
	return app_directory_;
}

void Application::Startup()
{
}

void Application::Shutdown()
{
}

} // namespace neuron