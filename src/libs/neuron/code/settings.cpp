#include "settings.h"
#include <fstream>
#include <nlohmann\json.hpp>
#include "core\debug.h"

namespace neuron
{



bool LoadProjectSettings(NString data_folder, ProjectSettings* settings)
{	
	std::ifstream in_stream;
	in_stream.open(data_folder.c_str());
	if (!in_stream.is_open())
	{
		DEBUG_LOG_ERROR("Impossible to open file: %s", data_folder.c_str());
		return false;
	}

	using json = nlohmann::json;
	json j;
	if (in_stream.is_open())
	{
		in_stream >> j;
		in_stream.close();
	}

	DEBUG_ASSERT_MSG(!j.is_null(), "Invalid json");
	if (j.is_null())
	{
		DEBUG_LOG_ERROR("Impossible to deserialize json file: %s", data_folder.c_str());
		return false;
	}

	return true;
}

} //namespace neuron.