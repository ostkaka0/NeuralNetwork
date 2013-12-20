#include <vector>

struct SNeuron;

struct SNeuronLayer
{
	int nNeurons;

	std::vector<SNeuron> neuronVector;

	SNeuronLayer(int neurons, int inputs);
};