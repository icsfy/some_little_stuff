#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  ofstream fout;
  cout << "Enter filename: ";
  char filename[20];
  cin.get(filename, 20);
  while(cin.get() != '\n');
  fout.open(filename,ios_base::out);
  if(!fout.is_open()) {
    cerr << "Cannot open output file: " << filename << endl;
    exit(EXIT_FAILURE);
  }
  cout << "Enter your message(EOF to quit):\n";
  char ch;
  while(cin.get(ch))
    fout << ch << flush;
  fout.close();
}
