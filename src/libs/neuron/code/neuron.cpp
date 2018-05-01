#include "neuron.h"
#include "core\neuron_types.h"
#include "core\filesystem.h"

#include <iostream>

namespace neuron{

int NeuronMain(int argc, char ** argv)
{
	if (argc <= 0)
	{
		std::cerr << "Invalid construction argument. No argument are passed in.\n";
		return 1;
	}

	//Get the executable relative folder.
	NString app_dir = filesystem::GetFolderFromPath(argv[0]);
	//Get the executable name.
	NString app_name = filesystem::GetFilenameFromPath(argv[0]);
	//Get the application data folder.
	NString app_data_dir = filesystem::CombinePaths(app_dir, app_name + "_data");


	std::cout << "Application directory: " << app_dir.c_str() << std::endl;
	std::cout << "Application name: " << app_name.c_str() << std::endl;
	std::cout << "Application data folder: " << app_data_dir.c_str() << std::endl;

	return 0;
}

} // namespace neuron.