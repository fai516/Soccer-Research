/* This header file only stores definitions */
/* The implementations are stored in the same name but in .cpp file */

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Player{
  unsigned int number;
  string position;

  unsigned int tPass;
  unsigned int sPass;
  unsigned int tShot;
  unsigned int sShot;

  unsigned int tPassRS;

  unordered_map<unsigned int, unsigned int> sPass_pvp; //sPass to each player.
  unordered_map<unsigned int, unsigned int> sPassES_pvp; //sPassES to each player.

  void showStat();
};

struct Team{
  vector<int> players; //all the players numbers are stored here
  unordered_map<unsigned int, Player* > playerHash; //store the connections of Player class

  //The big 4 criteria
  vector<double> PassingACC;
  vector<double> Performance;
  vector< unordered_map<unsigned int, unsigned int> > SucessfulPass;
  vector< unordered_map<unsigned int, unsigned int> > PassCentrality;

  void showStat();  //show all the value of this class.
  void printPlayerHash(Team in);
};
