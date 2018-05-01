#include "filesystem.h"
#include <filesystem> //experimental microsoft header.

/*
https://www.bfilipek.com/2017/08/cpp17-details-filesystem.html
*/

namespace neuron {
namespace filesystem {

namespace fs = std::experimental::filesystem;

NString GetFolderFromPath(NString path)
{
	fs::path program_path(path.c_str());
	auto program_dir = program_path.parent_path();
	NString app_dir = program_dir.string().c_str();
	return app_dir;
}

NString GetFilenameFromPath(NString path)
{
	fs::path target_path(path.c_str());
	auto target_path_filename = target_path.filename().stem();
	NString filename = target_path_filename.string().c_str();
	return filename;
}

NString CombinePaths(NString p1, NString p2)
{
	fs::path path(p1.c_str());
	path /= p2.c_str();
	return path.string().c_str();
}

} // namesoace filesystem.
} // namespace neuron.