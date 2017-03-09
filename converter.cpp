#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "soccerCSV.hpp"
using namespace std;

struct Path{
  
};

class Player{
  int number;
  string pos;
  int total_pass;
  unordered_map<unsigned int, unsigned int> successful_passes; //successful pass for all player.

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
      unordered_map<unsigned int, Player* > player_hash;  //hashing player's number to Player class;


      while(getline(infile,buffer)){  //Read line by line
        nLine++;
        SoocerCSV data_in(buffer); //convert a line of CSV raw file into CSV class



      }
      infile.close();

      //cout << player_hash[8] << endl;
      cout << "Process " << nLine << " lines."<< endl;
    }
  }

  return 0;
}
