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
      SoccerPath path;
      Team *SnT = new Team();
      bool isPass = true;
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
        Data.print();
        //cout << "#" << nLine << " " << Data.playerNum << endl;
        Data.fetchPlayer(SnT,path);

        if(Data.checkShot(SnT)){
          //path.print("ShotPath");
          isPass = false;
          path.clear();
        }
        else if(Data.checkPass(SnT)){
          isPass = true;
          int p2 = stoi(Data.PassTo);
          path.data.push_back(p2);
        }
        else{
          isPass = true;
          //path.print("PassPath");
          path.clear();
        }



        /****************************/
        /*            End           */
        /****************************/
      }
      if(isPass){
        path.print("PassPath");
        path.clear();
      }
      else{
        
      }
      //SnT->printPlayerHash();
      infile.close();
      delete SnT;

      cout << "Process " << nLine << " lines."<< endl;
    }
  }
  return 0;
}
