#pragma once
#include "core\neuron_types.h"
#include <EASTL\unique_ptr.h>
#include "settings.h"

namespace neuron {

class Application
{
public:
	Application(const char* executable_path);
	virtual ~Application();

	Application(const Application&) = delete;
	Application(Application&&) = delete;
	Application& operator=(const Application&) = delete;
	Application& operator=(Application&&) = delete;

public:
	
	NString Name();
	NString DataDirectory();
	NString AppDirectory();
	bool Startup();
	void Shutdown();
	/*virtual void Startup() = 0;
	virtual void Shutdown() = 0;
	virtual void Run() = 0;

	virtual void BeginFrameRendering() = 0;*/

private:

	NString app_name_;
	NString app_directory_;
	NString data_directory_;

	ProjectSettings project_settings_;

};
} // namespace neuron

