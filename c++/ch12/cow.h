#ifndef COW_H
#define COW_H
class Cow {
  char name[20];
  char * hobby;
  double weight;
public:
  Cow();
  Cow(const char * nm, const char * ho, double wt);
  Cow(const Cow & c);
  ~Cow();
  Cow & operator=(const Cow & c);
  void ShowCow() const;  //display all cow data
};

#endif

#ifndef COW_C
#define COW_C
#include <iostream>
#include <cstring>

Cow::Cow()
{
  name[0] = 'C', name[1] = 'o', name[2] = 'w', name[3] = '\0';
  hobby = new char[4];
  std::strcpy(hobby, "Cow's hobby");
  weight = 0.0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
  for(int i=0;nm[i] != '\0' && i<20;i++){
    name[i] = nm[i];
    i<19?name[i+1] = '\0':name[19]='\0';
  }
//  name[19] = '\0';
  hobby = new char[std::strlen(ho)+1];
  std::strcpy(hobby, ho);
  weight = wt;
}
Cow::Cow(const Cow & c)
{
  for(int i=0;c.name[i] != '\0' && i<20;i++){
    name[i] = c.name[i];
    i<19?name[i+1] = '\0':name[19]='\0';
  }
//  name[19] = '\0';
  hobby = new char[std::strlen(c.hobby)+1];
  std::strcpy(hobby, c.hobby);
  weight = c.weight;
}
Cow::~Cow()
{
  std::cout << " [" << name << ',' << hobby << ',' << weight << "] destoryed.\n";
  delete [] hobby;
}
Cow & Cow::operator=(const Cow & c)
{
  if(&c == this)
    return *this;
  delete [] hobby;
  for(int i=0;c.name[i] != '\0' && i<20;i++){
    name[i] = c.name[i];
    i<19?name[i+1] = '\0':name[19]='\0';
  }
//  name[19] = '\0';
  hobby = new char[std::strlen(c.hobby)+1];
  std::strcpy(hobby, c.hobby);
  weight = c.weight;  
  return *this;
}
void Cow::ShowCow() const
{
  std::cout << "      name: " << name << std::endl
            << "     hobby: " << hobby << std::endl
            << "    weight: " << weight << std::endl;
}
#endif
