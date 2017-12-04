#include <iostream>
#include <string>
#include <cstring>

//#include "person.h"
#ifndef PERSON_H
#define PERSON_H
class Person {
  private:
    static const int LIMIT = 25;
    std::string lname;  //Person's last name
    char fname[LIMIT];  //Person's first name
  public:
    Person() {lname = ""; fname[0] = '\0'; }  //#1
    Person(const std::string & ln, const char * fn = "Heyyou");  //#2
    void Show() const;  //firstname lastname format
    void FormalShow() const;  //lastname firstname format
};
#endif

//#include "person.c"
#ifndef PERSON_C
#define PERSON_C
Person::Person(const std::string & ln, const char * fn)
{
  lname = ln;
  for(int i=0;i<strlen(fn);i++){
    fname[i] = fn[i];
  }
}
void Person::Show() const
{
  std::cout << "Show(): " << fname << ", " << lname << std::endl;
}
void Person::FormalShow() const
{
  std::cout << "FormalShow(): " << lname << ", " << fname << std::endl;
}
#endif

int main()
{
  Person one;
  Person two("Smythecraft");
  Person three("Dimwiddy", "Sam");
  std::cout << "\none:\n";
  one.Show();
  one.FormalShow();
  std::cout << "\ntwo:\n";
  two.Show();
  two.FormalShow();
  std::cout << "\nthree:\n";
  three.Show();
  three.FormalShow();
}

