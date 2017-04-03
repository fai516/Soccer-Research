#include "Soccer.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>
void Player::showStat(vector<int> team){
  //cout << "sShotPath: " << this->sPassRS;
  cout << "\t: ";
  for(int i=0;i<team.size();i++){
    cout << team[i] << "(" << this->sPassPvP[team[i]] << ") ";
  }
}

void Team::printPlayerHash(){  //can be put in Team class
  for(int i=0;i<players.size();i++){
    cout << "Player#" << players[i] << "\tAddress: " << playerHash[players[i]] << endl;
  }
}

void Team::showStat(){
  for(int i=0;i<this->players.size();i++){
    cout << "#" << players[i] << "  ";
    Player *tmp = this->playerHash[players[i]];
    tmp->showStat(players);
    cout << endl;
  }
  cout << "TotalShotPath: " << tPathRS << endl;
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
  //consider repetation? Not yet.
  unordered_map<unsigned int, unordered_map<unsigned int,bool> > map;
  for(int i=1;i<this->data.size();i++){
    int p1=data[i]; int p2=data[i-1];
    Player *currentPlayer = team->playerHash[p1];
    Player *previousPlayer = team->playerHash[p2];

    if(currentPlayer == NULL || previousPlayer == NULL) { //exception handling
      cout << "Player#" << data[i-1] << " or Player# " << data[i] << " do not exist."; exit(0);
    }
    if(map[p1][p2] == false && map[p2][p1] == false){
      currentPlayer->sPassPvP[p2]++;
      previousPlayer->sPassPvP[p1]++;
      map[p1][p2] = true;
      map[p2][p1] = true;
    }
  }
}
void SoccerPath::registerTypeShot(Team *team){
  //consider repetation? Yes.
  unordered_map<unsigned int,bool> map;
  for(int i=0;i<this->data.size();i++){
    unsigned int PlayerNum = data[i];
    if(team->playerHash[PlayerNum] == NULL){
      Player *tmp = new Player();
      team->playerHash[PlayerNum] = tmp;
    }
    if(map[PlayerNum] == false){
      team->playerHash[PlayerNum]->sPassRS++;
      map[PlayerNum] = true;
    }
  }
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
