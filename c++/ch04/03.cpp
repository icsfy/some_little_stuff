#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char first_name[50],last_name[50];
  char name[100];
  
  cout << "Enter your first name: ";
  cin.getline(first_name, 50);
  cout << "Enter your last name: ";
  cin.getline(last_name, 50);

  strcpy(name, last_name);
  strcat(name, ", ");
  strcat(name, first_name);

  cout << "Here's the information in a single string: "
       << name <<endl;

  return 0;
}
