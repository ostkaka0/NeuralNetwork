#include <vector>
#include "SGenome.h"

class GenAlg
{
private:
  //this holds the entire population of chromosomes
  std::vector <SGenome> m_vecPop;
 
  //size of population
  int m_iPopSize;
 
  //amount of weights per chromo
  int m_iChromoLength;
 
  //total fitness of population
  double m_dTotalFitness;
 
  //best fitness this population
  double m_dBestFitness;
 
  //average fitness
  double m_dAverageFitness;
 
  //worst
  double m_dWorstFitness;
 
  //keeps track of the best genome
  int m_iFittestGenome;
 
  //probability that a chromosomes bits will mutate.
  //Try figures around 0.05 to 0.3 ish
  double m_dMutationRate;
 
  //probability of chromosomes crossing over bits
  //0.7 is pretty good
  double m_dCrossoverRate;
 
  //generation counter
  int m_cGeneration;
 
  void Crossover(const std::vector<double> &mum,
                 const std::vector<double> &dad,
                 std::vector<double>       &baby1,
                 std::vector<double>       &baby2);

  void Mutate(std::vector<double> &chromo);
 
  SGenome GetChromoRoulette();
 
  void GrabNBest(int             NBest,
                 const int       NumCopies,
                 std::vector<SGenome> &vecPop);
 
  void CalculateBestWorstAvTot();
 
  void Reset();
 
public:
	///<summary>
	///<para>Mutation rate is good between 0.005 and 0.3
	///<para>Cross over rate is good at 0.7
	///</summary>
	
  GenAlg(int    popsize,
          double MutRat,
          double CrossRat,
          int    numweights
		  );
 
  ///<summary>
  ///<para>this runs the GA for one generation.
  ///</summary>
  std::vector<SGenome> Epoch(std::vector<SGenome> &old_pop);
 
  //-------------------accessor methods
  std::vector<SGenome> GetChromos()const{return m_vecPop;}
  double AverageFitness()const{return m_dTotalFitness / m_iPopSize;}
  double BestFitness()const{return m_dBestFitness;}
};