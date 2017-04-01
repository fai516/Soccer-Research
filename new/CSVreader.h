#include <string>
#include <vector>
using namespace std;

struct CSVreader{
  vector<string> array;

  void CSVtoArray(string input, char s);

  void toSoccerData();
};
