#ifndef CD_H
#define CD_H
class Cd {
private:
  char performers[50];
  char label[20];
  int selections;
  double playtime;
public:
  Cd(const char * s1, const char * s2, int n, double x);
  Cd(const Cd & d);
  Cd();
  virtual ~Cd();
  virtual void Report() const;
  virtual Cd & operator=(const Cd & d);
};
#endif

#ifndef CD_CPP
#define CD_CPP
#include <iostream>
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
  for(int i=0; s1[i] != '\0' && i<50; i++){
    performers[i] = s1[i];
    i!=49?performers[i+1]='\0':performers[49]='\0';
  }
  for(int i=0; s2[i] != '\0' && i<20; i++){
    label[i] = s2[i];
    i!=19?label[i+1]='\0':label[19]='\0';
  }
  selections = n;
  playtime = x;
}
Cd::Cd(const Cd & d)
{
  for(int i=0; d.performers[i] != '\0' && i<50; i++){
    performers[i] = d.performers[i];
    i!=49?performers[i+1]='\0':performers[49]='\0';
  }
  for(int i=0; d.label[i] != '\0' && i<20; i++){
    label[i] = d.label[i];
    i!=19?label[i+1]='\0':label[19]='\0';
  }
  selections = d.selections;
  playtime = d.playtime;
}
Cd::Cd()
{
  performers[0]='p', performers[1]='\0';
  label[0]='l', label[1]='\0';
  selections = 0;
  playtime = 0.0;  
}
Cd::~Cd()
{
}
void Cd::Report() const
{
  std::cout << "               Performers: " << performers << std::endl
            << "                    Label: " << label << std::endl
            << "     Number of selections: " << selections << std::endl
            << "  Playing time in minutes: " << playtime << std::endl;
}
Cd & Cd::operator=(const Cd & d)
{
  if(this == &d)
    return *this;
  for(int i=0; d.performers[i] != '\0' && i<50; i++){
    performers[i] = d.performers[i];
    i!=49?performers[i+1]='\0':performers[49]='\0';
  }
  for(int i=0; d.label[i] != '\0' && i<20; i++){
    label[i] = d.label[i];
    i!=19?label[i+1]='\0':label[19]='\0';
  }
  selections = d.selections;
  playtime = d.playtime;
  return *this;
}
#endif
