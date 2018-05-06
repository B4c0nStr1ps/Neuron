#include "utils.h"
#include "EASTL\string.h"

namespace neuron
{

NId BuildID(const char * name)
{
	NString name_string(name);
	eastl::hash<eastl::string> hash_generator;
	return hash_generator(name_string);
}

} //namespace neuron.