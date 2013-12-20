#include <vector>
#include "SNeuronLayer.h"

class NeuralNetwork
{
	int nInputs;
	int nOutputs;
	int nHiddenLayers;
	int nNeuronPerLayer;

	std::vector <SNeuronLayer> layers;

public:
	NeuralNetwork();

	void CreateNetwork();
	std::vector<double> GetWedights() const;
	int GetNumberOfWeights() const;
	void PutWeights(std::vector<double> &weights);
	std::vector<double> Update(std::vector<double> &inputs);
	inline double Sigmoid(double activations, double response);
};