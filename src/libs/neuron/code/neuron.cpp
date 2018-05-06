#include "neuron.h"
#include "application.h"
#include "core\debug.h"

#include <iostream>

namespace neuron{

int NeuronMain(int argc, char ** argv)
{
	DEBUG_ASSERT_MSG(argc > 0, "Invalid construction argument. No argument are passed in.\n");

	auto app = eastl::make_unique<Application>(argv[0]);
	DEBUG_ASSERT_MSG(app != nullptr, "Error trying to construct the applicaiton class.\n");

	DEBUG_LOG("Application directory: %s", app->AppDirectory().c_str());
	DEBUG_LOG("Application name: %s", app->Name().c_str());
	DEBUG_LOG("Application data folder: %s", app->DataDirectory().c_str());

	return 0;
}

} // namespace neuron.