#ifndef NEURON_FILESYSTEM_H
#define NEURON_FILESYSTEM_H

#include "neuron_types.h"

namespace neuron {
namespace filesystem {

NString GetFolderFromPath(NString path);

NString GetFilenameFromPath(NString path);

NString CombinePaths(NString path_1, NString path_2);

} // namesoace filesystem.
} // namespace neuron.

#endif
