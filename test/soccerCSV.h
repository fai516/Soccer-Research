#include <string>
#include <vector>
using namespace std;

struct Player{
  int number;
  string pos;
  int total_pass;
  int total_pass_end_shot;
  unordered_map<unsigned int, unsigned int> successful_passes; //successful pass to all player.
  unordered_map<unsigned int, unsigned int> successful_passes_end_shot; //successful_passes_end_shot
};

struct Team{
  vector<unsigned int> players;
  unordered_map<unsigned int, Player* > player_hash;
};

struct SoccerCSV{
  string Time;             //Time                      #1
  string PlayerNumber;     //Player's number           #2  ]Posseccion
  string Area;             //Area                      #3  ]Posseccion
  string ROP;              //Result of Possession      #4  ]Posseccion
  string PassedToward;     //Passed toward             #5  ]Posseccion
  string OppPassedTimes;   //OPT before our possession #6  ]Defensive
  string Defensive;        //                          #7  ]Defensive
  string FoulCommited;     //                          #8  ]Displine
  string FoulDrawn;        //                          #9  ]Displine
  string Yellow;           //                          #10 ]Displine
  string Red;              //                          #11 ]Displine
  string Offsides;         //                          #12 ]Displine
  string OppTOC;           //                          #13 ]OppChance
  string OppDOS;           //                          #14 ]OppChance
  string OppROS;           //                          #15 ]OppChance
  string OppNOP;           //                          #16 ]OppChance
  string TOC;              //                          #17 ]OurChance
  string DOS;              //                          #18 ]OurChance
  string ROS;              //                          #19 ]OurChance
  string NOS;              //                          #20 ]OurChance
  string Shooter;          //                          #21 ]OurChance
  string FirstPass;        //                          #22 ]OurChance
  string SecondPass;       //                          #23 ]OurChance
  string ThirdPass;        //                          #24 ]OurChance
  string FourthPass;       //                          #25 ]OurChance

  vector<string> sPlayer;   //                          #26-36
  vector<string> sPosition; //                          #37-47

  string touch;
  SoccerCSV(vector<string> in){
    int selector=1;
    for(int sel=0;sel<25;sel++){
      switch(sel){
        case 0:Time = in[sel];break;
        case 1:PlayerNumber = in[sel];break;
        case 2:Area = in[sel];break;
        case 3:ROP = in[sel];break;
        case 4:PassedToward = in[sel];break;
        case 5:OppPassedTimes = in[sel];break;
        case 6:Defensive = in[sel];break;
        case 7:FoulCommited = in[sel];break;
        case 8:FoulDrawn = in[sel];break;
        case 9:Yellow = in[sel];break;
        case 10:Red = in[sel];break;
        case 11:Offsides = in[sel];break;
        case 12:OppTOC = in[sel];break;
        case 13:OppDOS = in[sel];break;
        case 14:OppROS = in[sel];break;
        case 15:OppNOP = in[sel];break;
        case 16:TOC = in[sel];break;
        case 17:DOS = in[sel];break;
        case 18:ROS = in[sel];break;
        case 19:NOS = in[sel];break;
        case 20:Shooter = in[sel];break;
        case 21:FirstPass = in[sel];break;
        case 22:SecondPass = in[sel];break;
        case 23:ThirdPass = in[sel];break;
        case 24:FourthPass = in[sel];break;
        default:break;
      }
    }
    vector<string>::iterator first  = in.begin()+25; //element 25
    vector<string>::iterator second = in.begin()+36;
    vector<string>::iterator third  = in.end();
    sPlayer.assign(first,second);
    sPosition.assign(second,third);
  }
  SoccerCSV(){ cout << "**Error: Require parameter(vector string) for constructor SoccerCSV" << endl; exit(0);}

  void print(){
    cout << "-------------------------------------------------------" << endl;
    cout << "@" << Time << "\t#" << PlayerNumber << "(" << Area << ")->#" << PassedToward << "=" << ROP<<endl;
    cout << OppPassedTimes << endl;
    for(int i=0;i<sPlayer.size();i++){
      cout << stoi(sPlayer[i]) << "." << sPosition[i] << endl;
    }
  }

  void fetchPlayer(Team &input){
    for(int i=0;i<sPlayer.size();i++){
      int num = stoi(sPlayer[i]);
      if(input.player_hash[num] == NULL){
        Player *tmp = new Player(); tmp->number=num; tmp->pos=sPosition[i];
        input.player_hash[num] = tmp;
        input.players.push_back(num);
      }
    }
  }
};
