#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> CSVconverter(string input, char s){
  vector<string> out;
  int last = -1;
  int count = 0;
  for(int i=0;i<input.size();i++){
    if(input[i] != s) count++;
    else{ // input[i]==s
      string buffer = input.substr(last+1,count);
      out.push_back(buffer);
      last=i;count=0;
    }
  }
  return out;
}
