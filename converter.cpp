#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "soccerCSV.h"
using namespace std;

/*
1.Passing acc for P(i)              PassAC(i)
2.Shoot acc for P(i)                ShotAC(i)
3.flow centrality(Play performance) FC(i)
4.pass(arc) centrality              AC(i)->(for every )
*/

class Path{
  int current_total;
  vector<int> path;
  Path(){current_total=0;}

};

int main(int argc, char* argv[]){

  string buffer;
  int nLine=0;
  if(argc != 2){
    cout << "Too much input parameter" << endl;
    exit(0);
  }
  else{
    ifstream infile(argv[1]);
    if(!infile.is_open()){
      cout << "Cannot find the file" << endl;
      exit(0);
    }
    else{
      vector<int> player;
      unordered_map<unsigned int, Player* > player_hash;  //hashing player's number to Player class;


      while(getline(infile,buffer)){  //Read line by line
        nLine++;
        SoccerCSV data_in(buffer); //convert a line of CSV raw file into CSV class
        //ScanPlayerPOS(data_in, player_hash);
        data_in.print();
      }
      infile.close();

      cout << "Process " << nLine << " lines."<< endl;
    }
  }

  return 0;
}
