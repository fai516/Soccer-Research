#include <iostream>
#include <string>
#include <fstream>
#include "SoccerGraph.h"
using namespace std;



int main(int argc, char* argv[]){
  vector< vector<unsigned int> > storage;
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
          path.registerTypeShot(SnT);
          path.clear();
          SnT->tPathRS++;
        }
        else if(Data.checkPass(SnT)){
          isPass = true;
          int p2 = stoi(Data.PassTo);
          path.data.push_back(p2);
        }
        else{
          isPass = true;
          path.registerTypePass(SnT);
          path.print("PassPath");
          storage.push_back(path.data);
          path.clear();
          SnT->tPath++;
        }



        /****************************/
        /*            End           */
        /****************************/
      }
      //for the last path
      if(isPass){
        path.registerTypePass(SnT);
        path.print("PassPath");
        storage.push_back(path.data);
        path.clear();
        SnT->tPath++;
      }
      else{
        path.registerTypeShot(SnT);
        SnT->tPathRS++;
      }
      //SnT->showStat();
      SnT->printPlayerHash();
      infile.close();
      //starting calculation
      SoccerGraph graph(SnT);
      graph.solvePassingACC();
      graph.solveShootingACC();
      graph.solvePerformance();
      graph.solvePassCentrality();
      //ending calculation
      delete SnT;

      cout << "Process " << nLine << " lines."<< endl;
    }
  }
  return 0;
}
