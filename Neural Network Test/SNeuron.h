#include <vector>

struct SNeuron
{
	int nInputs;
	std::vector<double> inputWeights;

	SNeuron(int inputs);
};