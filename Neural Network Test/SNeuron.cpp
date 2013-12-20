#include "SNeuron.h"
#include <stdlib.h>

SNeuron::SNeuron(int inputs)
{
	this->nInputs= inputs;

	inputWeights.reserve(inputs+1);

	for (int i=0; i<inputs+1; ++i)
	{
		inputWeights.push_back((double)(rand()%0x1000)/0x1000F);
	}
}