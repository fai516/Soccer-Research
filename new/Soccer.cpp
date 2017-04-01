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
