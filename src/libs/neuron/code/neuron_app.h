#pragma once
#include "core\neuron_types.h"

namespace neuron
{
class NeuronApp
{
public:
	NeuronApp(NString app_name, NString app_directory);
	virtual ~NeuronApp();

	NeuronApp(const NeuronApp&) = delete;
	NeuronApp(NeuronApp&&) = delete;
	NeuronApp& operator=(const NeuronApp&) = delete;
	NeuronApp& operator=(NeuronApp&&) = delete;

public:
	void Startup();
	void Shutdown();
	/*virtual void Startup() = 0;
	virtual void Shutdown() = 0;
	virtual void Run() = 0;

	virtual void BeginFrameRendering() = 0;*/

private:

	NString app_name_;
	NString app_directory;

};

} //namespace neuron
