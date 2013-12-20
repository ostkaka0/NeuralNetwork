#include <vector>

struct SGenome
{
  std::vector<double>  vecWeights;
  double dFitness;
  SGenome():dFitness(0){}
  SGenome(std::vector <double> w, double f): vecWeights(w), dFitness(f){}

  //overload '<' used for sorting
  friend bool operator<(const SGenome& lhs, const SGenome& rhs)
  {
    return (lhs.dFitness < rhs.dFitness);
  }

};