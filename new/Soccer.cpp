#include "Soccer.h"
#include <iostream>

void Player::showStat(){
  cout << "hello world" <<endl;
}

void Team::printPlayerHash(Team in){  //can be put in Team class
  for(int i=0;i<in.players.size();i++){
    cout << in.players[i] << "-" << in.playerHash[in.players[i]] << endl;
  }
}


/*
  1. Player#
  2. Position
  3. Possession
  4. PassTo#
  5. ShotType
  6. ResultOfShot
*/

void SoccerData::toSoccerData(){
  //need index 1,2,3,4,16,18
  int selector[]={1,2,3,4,16,18};
  int size = sizeof(selector)/sizeof(int);
  int count=0;

  int player;
  string position;
  string possession;
  int passTo;
  string ShotType;
  string ResultOfShot;

  vector<string> cpy;
  for(int i=0;i<array.size();i++){
    if(i == selector[count]){
      cpy.push_back(array[i]);
      if(count != size) count++;
    }
  }
  array.clear();
  array = cpy;
}
void SoccerData::assign(){
  for(int i=0;i<array.size();i++){
    switch(i){
      case 0: Player = stoi(array[i]); break;
      case 1: Position = array[i]; break;
      case 2: Possession = array[i]; break;
      case 3: PassTo = array[i]; break;
      case 4: ShotType = array[i]; break;
      case 5: ResultOfShot = array[i]; break;
      default: cout << "GG" << endl;exit(0);
    }
  }
}
void SoccerData::fetchPlayer(Team *team){
  
}
void SoccerData::checkShot(Team *team){}
void SoccerData::checkPass(Team *team){}
