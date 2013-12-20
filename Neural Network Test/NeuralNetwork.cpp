#include "NeuralNetwork.h"
#include "SNeuron.h"
#include <vector>

using namespace std;

vector<double> NeuralNetwork::Update(vector<double> &inputs)
{
	vector<double> outputs;

	int cWeight;

	if (inputs.size() != nInputs)
	{
		return outputs;
	}

	for (int i = 0; i < nHiddenLayers + 1; ++i)
	{
		if (i > 0)
		{
			inputs = outputs;
		}

		outputs.clear();

		cWeight = 0;

		for (int j = 0; j < layers[i].nNeurons; ++j)
		{
			double netInput = 0;

			int nInputs = layers[i].neuronVector[j].nInputs;
		
			for (int k = 0; k < nInputs - 1; ++k)
			{
				netInput += layers[i].neuronVector[j].inputWeights[k] *
					inputs[cWeight++];
			}

			//netInput += layers[i].nNeurons[j].weight[nInputs-1]*
			//	CParams::dBias;

			outputs.push_back(Sigmoid(netInput, 1.618));

			cWeight = 0;
		}
	}

	return outputs;
}