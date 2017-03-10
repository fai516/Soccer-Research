#include <string>
#include <vector>
using namespace std;
struct SoccerCSV{
  int nRecord;
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

  vector<string> Player;   //                          #26-36
  vector<string> Position; //                          #37-47

  SoccerCSV(string input){
    //cout << input << endl;
    int last_comma_pos = -1;
    int id=1,count=0;
    for(int i=0;i<input.size();i++){ //parsing string
      if(input[i] != ',') count++;
      else{
        if(count == 0) {id++;continue;}
        string buffer = input.substr(last_comma_pos+1,count);
        switch(id){
          case 1:Time = buffer;break;
          case 2:PlayerNumber = buffer;break;
          case 3:Area = buffer;break;
          case 4:ROP = buffer;break;
          case 5:PassedToward = buffer;break;
          case 6:OppPassedTimes = buffer;break;
          case 7:Defensive = buffer;break;
          case 8:FoulCommited = buffer;break;
          case 9:FoulDrawn = buffer;break;
          case 10:Yellow = buffer;break;
          case 11:Red = buffer;break;
          case 12:Offsides = buffer;break;
          case 13:OppTOC = buffer;break;
          case 14:OppDOS = buffer;break;
          case 15:OppROS = buffer;break;
          case 16:OppNOP = buffer;break;
          case 17:TOC = buffer;break;
          case 18:DOS = buffer;break;
          case 19:ROS = buffer;break;
          case 20:NOS = buffer;break;
          case 21:Shooter = buffer;break;
          case 22:FirstPass = buffer;break;
          case 23:SecondPass = buffer;break;
          case 24:ThirdPass = buffer;break;
          case 25:FourthPass = buffer;break;
          default: //cout << "Wrong id=" << id << endl;
          break;
        }
        id++; count = 0;
        last_comma_pos = i;
      }

    }
  }
  SoccerCSV(){ cout << "**Error: Require parameter for constructor SoccerCSV" << endl; exit(0);}

  void print(){
    cout << "-------------------------------------------------------" << endl;
    cout << "@" << Time << "\t#" << PlayerNumber << "(" << Area << ")->#" << PassedToward << "=" << ROP<<endl;
    cout << OppPassedTimes << endl;
  }
};

struct Player{
  int number;
  string pos;
  int total_pass;
  int total_pass_end_shot;
  unordered_map<unsigned int, unsigned int> successful_passes; //successful pass to all player.
  unordered_map<unsigned int, unsigned int> successful_passes_end_shot; //successful_passes_end_shot
};
