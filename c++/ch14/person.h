#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person
{
private:
  std::string lastname;
  std::string firstname;
public:
  Person(const char * fn = "FIRST_NAME(Person)", const char * ln = "LAST_NAME(Person)");
  virtual ~Person(){}
  virtual void Show() const;
};
#endif

#ifndef PERSON_CPP
#define PERSON_CPP
#include <iostream>
Person::Person(const char * fn, const char * ln)
{
  firstname = fn;
  lastname = ln;
}
void Person::Show() const
{
  std::cout << "    First Name: " << firstname << std::endl;
  std::cout << "    Last Name: " << lastname << std::endl;
}
#endif
