#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "CSVreader.h"
#include "soccerCSV.h"
using namespace std;

/* Main goal:
@1.Passing acc for P(i)              PassAC(i)=sPass(i)/tPass(i)  [Color of Node]
@2.Sucessful between 2 players                                    [Width of Edge]
@3.flow centrality(Play performance) FC(i)                        [Size of Node]
@4.pass(arc) centrality              AC(i)->(for every )          [Color of Edge]
@5.Shoot acc for P(i)                ShotAC(i)                    [graph]
*/

/*
  Procedure(Implementation Note)
#1 .CSV file -> break it line by line
#2 for each line, process speration of data entries (with ',') -> clean data;
#3 each clean dataline -> fetchPlayer info.(number,position,class address)
                       -> Player passing -> making path...coz you don't know yet if its a end_shot_path or not.
                          -> to whom?
                          -> do the same thing for "whom", because of arc centrality;
                          -> successful?
                       -> if shooting
                          -> (SOG,Goal)->[G],(SOT)->[W]
                          -> Who shoot?
                          -> successful? [G] defines as sucessful shoot.

#4 Normalize @1-@5

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
        vector<string> items = CSVconverter(buffer,',');
        SoccerCSV data_in(items); //convert a line of CSV raw file into CSV class
        data_in.fetchPlayer(SnT); //fetching player data from. Players will be dynamics allocated.
        /****************************/
        /*           Start          */
        /****************************/
        
        cout << nLine <<endl;
        data_in.checkShoot(SnT);

        /****************************/
        /*            End           */
        /****************************/
      }
      infile.close();
      //test here**
      Player *p9 = SnT.player_hash[9];
      p9->showStat(SnT.players);
      //printPlayerHash(SnT);
      cout << "Process " << nLine << " lines."<< endl;
    }
  }
  return 0;
}
