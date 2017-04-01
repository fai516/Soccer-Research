#include "CSVreader.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void CSVreader::CSVtoArray(string input, char s){
  int last = -1;
  int count = 0;
  for(int i=0;i<input.size();i++){
    if(input[i] != s) count++;
    else{ // input[i]==s
      string buffer = input.substr(last+1,count);
      array.push_back(buffer);
      last=i;count=0;
    }
  }
}

void CSVreader::toSoccerData(){
  //need index 1,2,3,4,16,18
  int selector[]={1,2,3,4,16,18};
  int size = sizeof(selector)/sizeof(int);
  int count=0;

  vector<string> cpy;
  for(int i=0;i<size;i++){
    if(i == selector[count]){
      cpy.push_back(array[i]);
      count++;
    }
  }
  array.clear();
  array = cpy;
}
