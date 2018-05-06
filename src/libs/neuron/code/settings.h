#ifndef NEURON_SETTINGS_H
#define NEURON_SETTINGS_H

#include "core\neuron_types.h"

namespace neuron
{

struct ProjectSettings
{
	int width;
	int height;
};

bool LoadProjectSettings(NString data_folder, ProjectSettings* settings);

} //namespace neuron.

#endif //NEURON_SETTINGS_H
