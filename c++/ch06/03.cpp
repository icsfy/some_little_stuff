#include <iostream>
using namespace std;

void menu();

int main(int argc, char const *argv[]) {
  menu();
  char ch;
  cin.get(ch).get();
  while (ch!='c'&&ch!='p'&&ch!='t'&&ch!='g') {
    cout << "Please enter a c, p, t, or g:";
    cin.get(ch).get();
  }
  switch (ch) {
    case 'c':cout << "Carnivore is interesing.\n";break;
    case 'p':cout << "Pianist play piano.\n";break;
    case 't':cout << "A maple is a tree.\n";break;
    case 'g':cout << "This is not a game.\n";break;
  }

  return 0;
}

void menu()
{
  cout << "Please enter one of the following choices:\n";
  cout << "c) carnivore\t" << "p) pianist\t" << endl;
  cout << "t) tree\t\t" << "g) game\t" << endl;
}
