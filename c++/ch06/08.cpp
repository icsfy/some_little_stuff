#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
const int SIZE = 512;

int main(int argc, char const *argv[]) {
  cout << "Enter a text file name: ";
  char filename[SIZE];
  cin.getline(filename, SIZE);
  ifstream inFile;
  inFile.open(filename);
  if(!inFile.is_open()){
    cout << "Could not open the file " << filename << endl;
    exit(EXIT_FAILURE);
  }
  char ch;
  int count = 0;
  while (inFile.get(ch)) {
    ++count;
  }
  if(inFile.eof()){
    cout << "End of file reached.\n";
  } else if (inFile.fail()) {
    cout << "Input terminated by data mismatch.\n";
  } else cout << "Input terminated for unknown reason.\n";

  inFile.close();
  cout << "Read " << count << " charactors." <<endl;
  return 0;
}
