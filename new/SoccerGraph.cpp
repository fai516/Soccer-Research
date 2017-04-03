#include "SoccerGraph.h"
#include <cmath>
#include <iostream>
using namespace std;

SoccerGraph::SoccerGraph(Team *team){
  this->creator = "Yik Fai Siu";

  //assigning team players
  this->players = team->players;

  //for each player
  for(int i=0;i<this->players.size();i++){
    Player *p = team->playerHash[ players[i] ];

    //assigning players positions;
    positions.push_back(p->position);

    //1.assigning PassingACC
    PassingACC.push_back( double(p->sPass)/p->tPass );
    //cout << this->players[i] << " "<< this->PassingACC[i] << endl;

    //2.assigning ShootingACC
    double tmp;
    if(p->tShot == 0) tmp = 0;
    else tmp = double(p->sShot)/p->tShot;
    ShootingACC.push_back(tmp);
    //cout << this->players[i] << " "<< this->ShootingACC[i] << endl;

    //3.assigning Performance
    Performance.push_back( double(p->sPassRS)/team->tPathRS );
    //cout << this->players[i] << " "<< this->Performance[i] << endl;

    //4.assigning SucessfulPass
    //got issue ex. 15->15 should be 0
    for(int j=0;j<this->players.size();j++){
      this->SucessfulPass[players[i]][players[j]] = p->sPassPvP[players[j]];
    }
    /*
    for(int j=0;j<this->players.size();j++){
      cout << players[i] << "->" << players[j] << "("
           <<this->SucessfulPass[players[i]][players[j]] << ")  ";
    }
    cout << endl;
    */

    //5.assigning PassCentrality
    for(int j=0;j<this->players.size();j++){
      double tmp = double(p->sPassPvP[players[j]]) / team->tPath;
      this->PassCentrality[players[i]][players[j]] = tmp;
    }

    /*
    for(int j=0;j<this->players.size();j++){
      double tmp = double(p->sPassPvP[players[j]]) / team->tPath;
      cout <<  "#" <<players[i] << "->" << players[j] << "("
           <<this->PassCentrality[players[i]][players[j]] << ")  ";
    }
    */
  }

}

void SoccerGraph::NormalizeForDouble(vector<double> &input){
  double sum=0;
  double average;
  double variance;
  double std;

  //calculate average
  for(int i=0;i<input.size();i++){
    sum += input[i];// sum up all value
  }
  average = sum / input.size();

  //calculate standard deviation
  sum=0;
  for(int i=0;i<input.size();i++){
    sum += pow(input[i]-average, 2);
  }


  variance = sum / input.size();
  std = sqrt(variance);

  //Normalize
  for(int i=0;i<input.size();i++){
    input[i] = (input[i]-average)/std;
  }

}

void SoccerGraph::solvePassingACC(){
  NormalizeForDouble(PassingACC);

  //sample check
  /*
  for(int i=0;i<this->players.size();i++){
    cout << this->players[i] << " "<< this->PassingACC[i] << endl;
  }
  */
}
void SoccerGraph::solveShootingACC(){
  NormalizeForDouble(ShootingACC);
}
void SoccerGraph::solvePerformance(){
  NormalizeForDouble(Performance);
}
void SoccerGraph::solveSucessfulPass(){}
void SoccerGraph::solvePassCentrality(){
  //tracker
  vector< pair<unsigned int,unsigned int> > tracker;
  double average;
  double sum=0;
  double variance;
  double std;
  int counter=0;

  //summing up and averaging
  for(int i=0;i<players.size();i++){
    for(int j=i+1;j<players.size();j++){
      //pair<unsigned int, unsigned int> tmp(players[i],players[j]);
      double tmp = PassCentrality[players[i]][players[j]];
      sum += pow(tmp-average,2);
      counter++;
    }
  }
  average = sum / counter;

  //calculating standard deviation
  sum = 0;
  for(int i=0;i<players.size();i++){
    for(int j=i+1;j<players.size();j++){
      //pair<unsigned int, unsigned int> tmp(players[i],players[j]);
      double tmp = PassCentrality[players[i]][players[j]];
      sum += tmp;
    }
  }
  variance = sum / counter;
  std = sqrt(variance);

  //normalize
  for(int i=0;i<players.size();i++){
    for(int j=i+1;j<players.size();j++){
      double &tmp = PassCentrality[players[i]][players[j]];
      tmp = (tmp-average)/std;
    }
  }

  //sample output
  /*
  for(int i=0;i<players.size();i++){
    for(int j=i+1;j<players.size();j++){
      //pair<unsigned int, unsigned int> tmp(players[i],players[j]);
      double tmp = PassCentrality[players[i]][players[j]];
      sum += tmp;
      counter++;
      cout << players[i] << "->" << players[j] << "("
           << tmp << ") ";
    }
    cout << endl;
  }
  */
}

void generateGEXF(){

}
