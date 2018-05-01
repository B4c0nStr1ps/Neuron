#include "neuron.h"
#include "application.h"

#include <iostream>

namespace neuron{

int NeuronMain(int argc, char ** argv)
{
	if (argc <= 0)
	{
		std::cerr << "Invalid construction argument. No argument are passed in.\n";
		return 1;
	}

	auto app = eastl::make_unique<Application>(argv[0]);
	if (app == nullptr)
	{
		std::cerr << "Error trying to construct the applicaiton class.\n";
		return 1;
	}

	std::cout << "Application directory: " << app->AppDirectory().c_str() << std::endl;
	std::cout << "Application name: " << app->Name().c_str() << std::endl;
	std::cout << "Application data folder: " << app->DataDirectory().c_str() << std::endl;

	return 0;
}

} // namespace neuron.