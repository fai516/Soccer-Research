#include <iostream>
#include <string>
#include <fstream>
#include "Soccer.h"
using namespace std;






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
      Team *SnT = new Team();
      while(getline(infile,buffer)){  //Read line by line
        nLine++;
        SoccerData Data;
        Data.CSVtoArray(buffer,',');
        Data.toSoccerData();  // transfer to soccer data
        Data.assign();
        /****************************/
        /*           Start          */
        /****************************/
        //cout << "#" << nLine << " ";
        //data_in.checkShoot(SnT);
        //Data.print();
        //cout << "#" << nLine << " " << Data.PassTo << endl;
        Data.fetchPlayer(SnT);

        /****************************/
        /*            End           */
        /****************************/
      }
      infile.close();
      delete SnT;
      //test here**
      //Player *p9 = SnT.player_hash[9];
      //p9->showStat(SnT.players);
      //printPlayerHash(SnT);
      cout << "Process " << nLine << " lines."<< endl;
    }
  }
  return 0;
}
