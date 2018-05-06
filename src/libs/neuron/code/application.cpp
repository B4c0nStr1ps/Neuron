#include "application.h"
#include "core\debug.h"
#include "core\filesystem.h"

namespace neuron {

Application::Application(const char* executable_path)
{
	//Get the executable relative folder.
	app_directory_ = filesystem::GetFolderFromPath(executable_path);
	//Get the executable name.
	app_name_ = filesystem::GetFilenameFromPath(executable_path);
	//Get the application data folder.
	data_directory_ = filesystem::CombinePaths(app_directory_,  app_name_ + "_data");
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
	return data_directory_;
}

NString Application::AppDirectory()
{
	return app_directory_;
}

bool Application::Startup()
{
	//Load project settings

	NString project_settings_path = neuron::filesystem::CombinePaths(DataDirectory(), "settings.json");

	if (!LoadProjectSettings(project_settings_path, &project_settings_))
	{
		DEBUG_LOG_ERROR("Startup aborted!");
		return false;
	}

	return true;
}

void Application::Shutdown()
{
}

} // namespace neuron