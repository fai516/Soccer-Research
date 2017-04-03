#include <vector>
#include <string>
#include "Soccer.h"


struct SoccerGraph{
  string creator;

  vector<int> players;
  vector<string> positions;

  SoccerGraph();
  SoccerGraph(Team *team);

  //The big 4 criteria
  vector<double> PassingACC;  //need to normalize
  vector<double> ShootingACC;
  vector<double> Performance; //need to normalize
  unordered_map<unsigned int, unordered_map<unsigned int, unsigned int> > SucessfulPass;  //
  unordered_map<unsigned int, unordered_map<unsigned int, double> > PassCentrality; //

  void solvePassingACC();
  void solveShootingACC();
  void solvePerformance();
  void solveSucessfulPass();
  void solvePassCentrality();

  void NormalizeForDouble(vector<double> &input);

  void generateGEXF();
};
