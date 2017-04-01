#include <string>
#include <vector>
using namespace std;

struct CSVreader{
  friend struct Team;
  vector<string> array;

  void CSVtoArray(string input, char s);
  
  void print();
};
