/* This header file only stores definitions */
/* The implementations are stored in the same name but in .cpp file */

#include "CSVreader.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Player;
struct Team;
struct SoccerData;
struct SoccerPath;

struct Player{
  unsigned int number;
  string position;

  unsigned int tPass;
  unsigned int sPass;
  unsigned int tShot;
  unsigned int sShot;


  unordered_map<unsigned int, unsigned int> sPassPvP; //sPass to each player.
  unsigned int sPassRS; //sPassRS to each player.

  void showStat(vector<int> team);
};

struct Team{
  vector<int> players; //all the players numbers are stored here
  unordered_map<unsigned int, Player* > playerHash; //store the connections of Player class

  ~Team();

  int tPath;
  int tPathRS;

  void showStat();  //show all the value of this class.
  void printPlayerHash();
};

struct SoccerData : public CSVreader{
  unsigned int playerNum;
  string Position;
  string Possession;
  string PassTo;
  string ShotType;
  string ResultOfShot;

  void toSoccerData();
  void assign();

  void fetchPlayer(Team *team, SoccerPath &path);
  bool checkShot(Team *team);
  bool checkPass(Team *team);
  bool checkPossession(Team *team);
};

struct SoccerPath{
  vector<unsigned int> data;

  void sort();
  void registerTypePass(Team *team);
  void registerTypeShot(Team *team);
  void clear();
  void print(string type);
};
