#include <string>
using namespace std;
struct SoocerCSV{
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

  string Player1;          //                          #26
  string Player2;          //                          #27
  string Player3;          //                          #28
  string Player4;          //                          #29
  string Player5;          //                          #30
  string Player6;          //                          #31
  string Player7;          //                          #32
  string Player8;          //                          #33
  string Player9;          //                          #34
  string Player10;         //                          #35
  string Player11;         //                          #36

  string Position1;        //                          #37
  string Position2;        //                          #38
  string Position3;        //                          #39
  string Position4;        //                          #40
  string Position5;        //                          #41
  string Position6;        //                          #42
  string Position7;        //                          #43
  string Position8;        //                          #44
  string Position9;        //                          #45
  string Position10;       //                          #46
  string Position11;       //                          #47

  SoocerCSV(string input){
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
          case 26:Player1 = buffer;break;
          case 27:Player2 = buffer;break;
          case 28:Player3 = buffer;break;
          case 29:Player4 = buffer;break;
          case 30:Player5 = buffer;break;
          case 31:Player6 = buffer;break;
          case 32:Player7 = buffer;break;
          case 33:Player8 = buffer;break;
          case 34:Player9 = buffer;break;
          case 35:Player10 = buffer;break;
          case 36:Player11 = buffer;break;
          case 37:Position1 = buffer;break;
          case 38:Position2 = buffer;break;
          case 39:Position3 = buffer;break;
          case 40:Position4 = buffer;break;
          case 41:Position5 = buffer;break;
          case 42:Position6 = buffer;break;
          case 43:Position7 = buffer;break;
          case 44:Position8 = buffer;break;
          case 45:Position9 = buffer;break;
          case 46:Position10 = buffer;break;
          case 47:Position11 = buffer;break;
          default: //cout << "Wrong id=" << id << endl;
                  break;
        }
        id++; count = 0;
        last_comma_pos = i;
      }

    }
  }
  SoocerCSV(){ cout << "**Error: Require parameter for constructor SoocerCSV" << endl; exit(0);}

  void print(){
    cout << "-------------------------------------------------------" << endl;
    cout << "@" << Time << "\t#" << PlayerNumber << "(" << Area << ")->#" << PassedToward << "=" << ROP<<endl;
  }
};
