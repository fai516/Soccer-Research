#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "CSVreader.h"
#include "soccerCSV.h"
using namespace std;

/*
1.Passing acc for P(i)              PassAC(i)
2.Shoot acc for P(i)                ShotAC(i)
3.flow centrality(Play performance) FC(i)
4.pass(arc) centrality              AC(i)->(for every )
*/

void printPlayerHash(Team in){  //can be put in Team class
  for(int i=0;i<in.players.size();i++){
    cout << in.players[i] << "." << in.player_hash[in.players[i]] << endl;
  }
}

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
      Team SnT;


      while(getline(infile,buffer)){  //Read line by line
        nLine++;
        vector<string> item = CSVconverter(buffer,',');
        SoccerCSV data_in(item); //convert a line of CSV raw file into CSV class
        data_in.fetchPlayer(SnT);
        //printPlayerHash(player,player_hash);
        //data_in.print();
      }
      infile.close();
      printPlayerHash(SnT);
      cout << "Process " << nLine << " lines."<< endl;
    }
  }
  return 0;
}
