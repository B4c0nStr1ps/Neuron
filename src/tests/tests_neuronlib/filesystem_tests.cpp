#include <gtest\gtest.h>
#include "..\..\libs\neuron\code\core\neuron_types.h"
#include "..\..\libs\neuron\code\core\filesystem.h"

TEST(filesystem, GetFolderFromPath)
{
	neuron::NString path_1 = "C:\\Programs\\MyApp\\Test.sda";
	auto result_1 = neuron::filesystem::GetFolderFromPath(path_1);
	EXPECT_EQ(result_1, "C:\\Programs\\MyApp");

	neuron::NString path_2 = "C:\\Programs\\MyApp\\";
	auto result_2 = neuron::filesystem::GetFolderFromPath(path_2);
	EXPECT_EQ(result_2, "C:\\Programs\\MyApp");	

	neuron::NString path_3 = "\\Programs\\MyApp\\";
	auto result_3 = neuron::filesystem::GetFolderFromPath(path_3);
	EXPECT_EQ(result_3, "\\Programs\\MyApp");

	neuron::NString path_4 = "C:\\Programs\\MyApp\\file.exe\\test.sda";
	auto result_4 = neuron::filesystem::GetFolderFromPath(path_4);
	EXPECT_EQ(result_4, "C:\\Programs\\MyApp\\file.exe");

	neuron::NString path_5 = "C:\\Programs\\MyApp\\.exe\\test.sda";
	auto result_5 = neuron::filesystem::GetFolderFromPath(path_5);
	EXPECT_EQ(result_5, "C:\\Programs\\MyApp\\.exe");
}

TEST(filesystem, GetFilenameFromPath)
{
	neuron::NString path_1 = "C:\\Programs\\MyApp\\Test.sda";
	auto result_1 = neuron::filesystem::GetFilenameFromPath(path_1);
	EXPECT_EQ(result_1, "Test");

	neuron::NString path_2 = "\\MyApp\\Test.sda";
	auto result_2 = neuron::filesystem::GetFilenameFromPath(path_2);
	EXPECT_EQ(result_2, "Test");

	neuron::NString path_3 = "MyApp\\Test.sda";
	auto result_3 = neuron::filesystem::GetFilenameFromPath(path_3);
	EXPECT_EQ(result_3, "Test");

	neuron::NString path_4 = "MyApp\\.exe\\Test.sda";
	auto result_4 = neuron::filesystem::GetFilenameFromPath(path_4);
	EXPECT_EQ(result_4, "Test");
}

TEST(filesystem, CombinePaths)
{
	neuron::NString path_1 = "C:\\Programs\\";
	neuron::NString path_2 = "\\MyApp\\Test.sda";
	auto result = neuron::filesystem::CombinePaths(path_1, path_2);
	EXPECT_EQ(result, "C:\\Programs\\\\MyApp\\Test.sda");

	path_2 = "MyApp\\Test.sda";
	result = neuron::filesystem::CombinePaths(path_1, path_2);
	EXPECT_EQ(result, "C:\\Programs\\MyApp\\Test.sda");
}