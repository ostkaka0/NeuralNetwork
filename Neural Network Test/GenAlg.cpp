#include <stdlib.h>
#include "GenAlg.h"

void GenAlg::Crossover(const std::vector<double> &mum,
                 const std::vector<double> &dad,
                 std::vector<double>       &baby1,
                 std::vector<double>       &baby2)
{
	int mumEnd = rand()%(mum.size()-2)+1;
	int dadEnd = rand()%(mum.size()-2)+1;

	baby1.insert(baby1.end(), mum.begin(), mum.begin()+mumEnd);
	baby1.insert(baby1.end(), dad.begin()+dadEnd, dad.end());

	baby2.insert(baby2.end(), dad.begin(), dad.begin()+dadEnd);
	baby2.insert(baby2.end(), mum.begin()+mumEnd, mum.end());
}

void GenAlg::Mutate(std::vector<double> &chromo)
{
	chromo[rand()%chromo.size()] = rand()%2048 / 1024.0 - 1.0;
}
 
SGenome GenAlg::GetChromoRoulette()
{
	return m_vecPop[rand()%m_vecPop.size()];
}
 
void GenAlg::GrabNBest(int             NBest,
                 const int       NumCopies,
                 std::vector<SGenome> &vecPop)
{

}
 
void GenAlg::CalculateBestWorstAvTot()
{

}
 
void GenAlg::Reset()
{
	m_vecPop.clear();

	m_vecPop.reserve(m_iPopSize);

	for (int i = 0; i < m_iPopSize; i++)
	{
		SGenome genome;

		genome.vecWeights.reserve(m_iChromoLength);

		for (int j = 0; j < m_iChromoLength; j++)
			genome.vecWeights.push_back(rand()%2048 / 1024.0 - 1.0);

		m_vecPop.push_back(genome);
	}
}
 
GenAlg::GenAlg(int popsize,
          double MutRat,
          double CrossRat,
          int numweights)
		  : m_iPopSize(popsize)
		  , m_dMutationRate(MutRat)
		  , m_dCrossoverRate(CrossRat)
		  , m_iChromoLength(numweights)
{
	Reset();
}
 
  //this runs the GA for one generation.
std::vector<SGenome> Epoch(std::vector<SGenome> &old_pop)
{
	return old_pop;
}


