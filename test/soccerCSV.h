#include <string>
#include <vector>
using namespace std;


struct Player{
  int number;
  string pos;
  int tPass;    //total pass
  int sPass;    //successful pass (unversal)
  int tPassES;  //total pass end in a shot
  int sPassES;  //total pass end in a shot (unversal)
  unordered_map<unsigned int, unsigned int> sPass_pvp; //sPass to respective player.
  unordered_map<unsigned int, unsigned int> sPassES_pvp; //sPassES to respective player.

  int total_shot;
  int successful_shot;

  void showStat(vector<unsigned int> teammate){
      cout<<"#"<<number<<" "<<pos
          <<"\tPass: "<<sPass<<"/"<<tPass
          <<"\tPassES: "<<sPassES<<"/"<<tPassES<<endl;
      cout<<"sPass_pvp: ";
      for(int i=0;i<teammate.size();i++){
        if(teammate[i]==number) continue;
        else{
            cout << teammate[i] << "-(" << sPass_pvp[teammate[i]] << ")  ";
        }
      }
      cout<<endl;
      cout<<"sPassES_pvp: ";
      for(int i=0;i<teammate.size();i++){
        if(teammate[i]==number) continue;
        else{
            cout << teammate[i] << "-(" << sPassES_pvp[teammate[i]] << ")  ";
        }
      }
  }
};

struct Team{
  vector<unsigned int> players;
  unordered_map<unsigned int, Player* > player_hash;

  vector<double> PassingACC;
  vector<double> Performance;
  vector<int> sucessful_pass;
  vector<double> PassCentrality;
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

  string touches;
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

  void checkShoot(Team &input){
    if(!TOC.empty()){
      cout << PlayerNumber<<" "<< Shooter << " " << TOC << endl;
      int s = stoi(Shooter);
      Player* shooter = input.player_hash[s];
      if(shooter == NULL){cout << "unexpected error: shooter is NULL"<<endl;exit(0);}
      else if(ROS == "SOT"){shooter->total_shot++;}
      else{shooter->total_shot++;shooter->successful_shot++;}

      //cout << shooter->number << " performs " << ROS << ". Stat: " << shooter->successful_shot++ << "/" << shooter->total_shot << endl;
    }
    //else{cout<<"Not a shoot."<<endl;}
  }
};
