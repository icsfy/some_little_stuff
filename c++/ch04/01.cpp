#include <iostream>
#include <string>
using namespace std;

struct student 
{
  string first_name;
  string last_name;
  char grade;
  int age;
};

int main()
{
  student *stu = new student;

  cout << "What is your first name? ";
  getline(cin, stu->first_name);
  cout << "What is your last name? ";
  getline(cin, stu->last_name);
  cout << "What letter grade do you deserve? ";
  cin >> stu->grade;
  stu->grade++;
  cout << "What is your age? ";
  cin >> stu->age;

  cout << "Name: " << stu->last_name << ", " << stu->first_name
       <<endl
       << "Grade: " << stu->grade
       <<endl
       << "Age: " << stu->age
       <<endl;

  delete stu;
}
