#include "Soccer.h"
#include <iostream>
#include <algorithm>

void Player::showStat(){
  cout << "hello world" <<endl;
}

void Team::printPlayerHash(){  //can be put in Team class
  for(int i=0;i<players.size();i++){
    cout << players[i] << "-" << playerHash[players[i]] << endl;
  }
}

Team::~Team(){
  for(int i=0;i<this->players.size();i++){
    Player *tmp = this->playerHash[this->players[i]];
    delete tmp;
    this->playerHash[this->players[i]] = NULL;
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
      case 0: playerNum = stoi(array[i]); break;
      case 1: Position = array[i]; break;
      case 2: Possession = array[i]; break;
      case 3: PassTo = array[i]; break;
      case 4: ShotType = array[i]; break;
      case 5: ResultOfShot = array[i]; break;
      default: cout << "GG" << endl;exit(0);
    }
  }
}
void SoccerData::fetchPlayer(Team *team, SoccerPath &path){
  if(team->playerHash[playerNum] == NULL){
    Player *p = new Player();
    team->playerHash[playerNum] = p;
    team->players.push_back(playerNum);
    p->position = this->Position;
  }
  else{
    Player *p = team->playerHash[playerNum];
    p->position = this->Position;
  }

  if(path.data.empty()) path.data.push_back(playerNum);
}
bool SoccerData::checkShot(Team *team){
  Player *p = team->playerHash[playerNum];
  if(!ShotType.empty()){
    p->tShot++; //total shot of player increament
    if(ResultOfShot != "SOT"){ // Not shot out of target
      p->sShot++; //successful shot of player increament
    }
    return true;
  }
  else return false; //checkPass
}
bool SoccerData::checkPass(Team *team){
  Player *p1 = team->playerHash[playerNum];
  if(!PassTo.empty()){  //it's a pass
    p1->tPass++;
    if(checkPossession(team)){
      p1->sPass++;
      return true;
    }
    else return false;
  }
  else return false;
}
bool SoccerData::checkPossession(Team *team){
  if(Possession == "1") return true;
  else return false;
}


void SoccerPath::sort(){
  std::sort(this->data.begin(),this->data.end());
}

void SoccerPath::registerTypePass(Team *team){
  this->sort();

}
void SoccerPath::registerTypeShot(Team *team){
  this->sort();

}
void SoccerPath::clear(){
  this->data.clear();
}

void SoccerPath::print(string type){
  cout << type << ": ";
  for(int i=0;i<this->data.size();i++){
    cout << this->data[i] << ",";
  }
  cout << endl;
}
