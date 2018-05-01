cmake_minimum_required (VERSION 3.9)

#define required EASTL path
set(EASTL_ROOT_DIR "D:/Repos/EASTL" CACHE PATH "Path to the cloned EASTL repo")
include_directories (${EASTL_ROOT_DIR}/include)
include_directories (${EASTL_ROOT_DIR}/test/packages/EAAssert/include)
include_directories (${EASTL_ROOT_DIR}/test/packages/EABase/include/Common)
include_directories (${EASTL_ROOT_DIR}/test/packages/EAMain/include)
include_directories (${EASTL_ROOT_DIR}/test/packages/EAStdC/include)
include_directories (${EASTL_ROOT_DIR}/test/packages/EATest/include)
include_directories (${EASTL_ROOT_DIR}/test/packages/EAThread/include)
set(EASTL_LIBRARY debug ${EASTL_ROOT_DIR}/build/Debug/EASTL.lib optimized ${EASTL_ROOT_DIR}/build/Release/EASTL.lib)
add_custom_target(NatVis SOURCES ${EASTL_ROOT_DIR}/doc/EASTL.natvis)

set(GTESTS_BIN_DIR "D:/Repos/Git/googletest/build/googletest" CACHE PATH "Path to the builded gtest lib")
set(GTESTS_INCLUDE_DIR "D:/Repos/Git/googletest/googletest/include" CACHE PATH "Path to the include gtests")
include_directories(${GTESTS_INCLUDE_DIR})
set(GTESTS_LIBRARY debug ${GTESTS_BIN_DIR}/Debug/gtest.lib optimized ${GTESTS_BIN_DIR}/Release/gtest.lib)

set(FX11_BIN_DIR "D:/Repos/FX11/build/bin" CACHE PATH "Path to the builded Effect11 lib")
set(FX11_INCLUDE_DIR "D:/Repos/FX11/build/include" CACHE PATH "Path to the include Effect11 lib")
include_directories(${FX11_INCLUDE_DIR})
set(FX11_LIBRARY debug ${FX11_BIN_DIR}/Effects11d.lib optimized ${FX11_BIN_DIR}/Effects11.lib)

set(TOOLS_CMAKE_DIR "${CMAKE_CURRENT_LIST_DIR}")
include("${TOOLS_CMAKE_DIR}/Macros.cmake")

project (Neuron)
# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#find libraries
#find_library(GTESTS_LIB_DEBUG NAMES gtestd PATHS "${PROJECT_SOURCE_DIR}/external/bin/x64/debug")
#find_library(GTESTS_LIB_RELEASE NAMES gtest PATHS "${PROJECT_SOURCE_DIR}/external/bin/x64/release")

#build neuron.lib project
GetFilesWithSourceGroups(GLOB_RECURSE NEURON_LIB_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/libs/neuron)
add_library(neuron STATIC ${NEURON_LIB_FILES})
target_compile_definitions(neuron PUBLIC DLL_A) #define for dllexport
if(MSVC)
    target_compile_definitions(neuron PUBLIC -DUNICODE -D_UNICODE)
endif()
set_target_properties(neuron PROPERTIES FOLDER Libs)
target_link_libraries(neuron ${EASTL_LIBRARY})
target_link_libraries(neuron d3d11)
target_link_libraries(neuron ${FX11_LIBRARY})

#build gamedemo1.exe project
GetFilesWithSourceGroups(GLOB_RECURSE GDEMO1_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/apps/GameDemo1)
add_executable(GameDemo1 ${GDEMO1_FILES})
if(MSVC)
    target_compile_definitions(GameDemo1 PUBLIC -DUNICODE -D_UNICODE)
endif()
set_target_properties(GameDemo1 PROPERTIES FOLDER Demo)
target_link_libraries(GameDemo1 neuron)

#build tests project
GetFilesWithSourceGroups(GLOB_RECURSE GTESTS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/tests/tests_neuronlib)
add_executable(TestsNeuron ${GTESTS_FILES})
if(MSVC)
    target_compile_definitions(TestsNeuron PUBLIC -DUNICODE -D_UNICODE)
endif()
set_target_properties(TestsNeuron PROPERTIES FOLDER Tests)
target_link_libraries(TestsNeuron neuron)
target_link_libraries(TestsNeuron ${EASTL_LIBRARY})
target_link_libraries(TestsNeuron ${GTESTS_LIBRARY})