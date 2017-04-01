#include "CSVreader.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void CSVreader::CSVtoArray(string input, char s){
  array.clear();
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

void CSVreader::print(){
  for(int i=0;i<array.size();i++){
    cout << array[i] << " ";
  }
  cout << endl;
}
