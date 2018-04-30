#pragma once

namespace neuron
{
class NeuronApp
{
public:
	NeuronApp();
	virtual ~NeuronApp();

	NeuronApp(const NeuronApp&) = delete;
	NeuronApp(NeuronApp&&) = delete;
	NeuronApp& operator=(const NeuronApp&) = delete;
	NeuronApp& operator=(NeuronApp&&) = delete;

	/*virtual void Startup() = 0;
	virtual void Shutdown() = 0;
	virtual void Run() = 0;

	virtual void BeginFrameRendering() = 0;*/
};

} //namespace neuron
