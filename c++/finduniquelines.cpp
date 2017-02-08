// Find unique lines from a input file
// No sorting
// Compile: g++ finduniquelines.cpp -std=c++11
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " [input.txt] [output.txt]" << endl;
    exit(EXIT_FAILURE);
  }
  ifstream fin(argv[1]);
  ofstream fout(argv[2]);
  if (!fin.is_open()) {
    cerr << "Could not open input file: " << argv[1] << endl;
    exit(EXIT_FAILURE);
  }
  if (!fout.is_open()) {
    cerr << "Could not open output file: " << argv[2] << endl;
    exit(EXIT_FAILURE);
  }
  vector<string> vistr;  // for input.txt
  string temp;
  while (fin) {
    getline(fin, temp);
    vistr.push_back(temp);
  }
  fin.close();
  
  cout << "Read " << vistr.size() << " lines from " << argv[1] << endl;

  auto pvi = vistr.begin();
//  for (pvi; pvi != vistr.end(); pvi++) {
//    cout << *pvi << endl;
//  }

  vector<string> vostr;  // for output.txt
  bool uniq = true;
  auto pvo = vostr.begin();

  for (pvi = vistr.begin(); pvi != vistr.end(); pvi++) {
    for (pvo = vostr.begin(); pvo != vostr.end(); pvo++) {
      if (*pvi == *pvo) {
        uniq = false;
        break;
      }
    }
    if (uniq) {
      vostr.push_back(*pvi);
    }
    uniq = true;
  }

  for (pvo = vostr.begin(); pvo != vostr.end(); pvo++) {
    fout << *pvo << endl;
  }
  fout.close();

  cout << "Found " << vostr.size() << " unique lines.\n"
       << "Save to file: " << argv[2] << endl;

  return 0;
}
