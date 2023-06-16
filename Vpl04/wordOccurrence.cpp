#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

void mapstring(string text, map<string, int> &mapfreq) {
  stringstream separate(text);
  string word;
  while (separate >> word) {
    mapfreq[word]++;
  }
}

string freq(string text, map<string, int> mapfreq) {
  mapstring(text, mapfreq);
  string wordsup;
  auto max = mapfreq.begin();
  for (auto it = mapfreq.begin(); it != mapfreq.end(); it++) {
    if (it->second > max->second) {
      max = it;
    }
  }
  return max->first;
}

int main() {
  string text = "", line;
  map<string, int> mapfreq;
  while (getline(cin, line)) {
    if (cin.fail()) {
      break;
    } else {
      text = text + line + "\n";
    }
  }
  cout << endl << freq(text, mapfreq) ;
  return 0;
}