#include <iostream>
#include "emp.h"
abstr_emp::abstr_emp()
{
  fname = "FIRST_NAME(abstr_emp)";
  lname = "LAST_NAME(abstr_emp)";
  job = "JOB(abstr_emp)";
}
abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j)
{
  fname = fn;
  lname = ln;
  job = j;
}
void abstr_emp::ShowAll() const
{
  std::cout << "    First Name: " << fname << std::endl;
  std::cout << "     Last Name: " << lname << std::endl;
  std::cout << "           Job: " << job << std::endl;
}
void abstr_emp::SetAll()
{
  while(std::cin.get() != '\n')
    continue;
  std::cout << ">>Input first name: ";
  getline(std::cin, fname);
  std::cout << ">>Input last name: ";
  getline(std::cin, lname);
  std::cout << ">>Input job: ";
  getline(std::cin, job);
}
std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
  os << e.fname << ", " << e.lname;
  return os;
}
abstr_emp::~abstr_emp()
{}
employee::employee()
{}
employee::employee(const std::string & fn, const std::string & ln, const std::string & j) : abstr_emp(fn, ln, j)
{}
void employee::ShowAll() const
{
  abstr_emp::ShowAll();
}
void employee::SetAll()
{
  abstr_emp::SetAll();
}
manager::manager()
{}
manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico) : abstr_emp(fn, ln, j)
{
  inchargeof = ico;
}
manager::manager(const abstr_emp & e, int ico) : abstr_emp(e)
{
  inchargeof = ico;
}
manager::manager(const manager & m) : abstr_emp(m)
{
  inchargeof = m.inchargeof;
}
void manager::ShowAll() const
{
  abstr_emp::ShowAll();
  std::cout << "       Managed: " << inchargeof << std::endl;
}
void manager::SetAll()
{
  abstr_emp::SetAll();
  std::cout << ">>Input number of abstr_emps managed: ";
  std::cin >> inchargeof;
  while(std::cin.get() != '\n')
    continue;
}
fink::fink() : abstr_emp()
{
  reportsto = "REPORTSTO(fink)";
}
fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo) : abstr_emp(fn, ln, j)
{
  reportsto = rpo;
}
fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e)
{
  reportsto = rpo;
}
fink::fink(const fink & e) : abstr_emp(e)
{
  reportsto = e.reportsto;
}
void fink::ShowAll() const
{
  abstr_emp::ShowAll();
  std::cout << "    Reports to: " << reportsto << std::endl;
}
void fink::SetAll()
{
  abstr_emp::SetAll();
  std::cout << ">>To whom fink reports: ";
  getline(std::cin, reportsto);
}
highfink::highfink():abstr_emp(),manager(),fink()
{}
highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{}
highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{}
highfink::highfink(const fink & f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{
}
highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{}
highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h)
{}
void highfink::ShowAll() const
{
  abstr_emp::ShowAll();
//  manager::ShowAll();
//  fink::ShowAll();
  std::cout << "       Managed: " << InChargeOf() << std::endl;
  std::cout << "    Reports to: " << ReportsTo() << std::endl;
}
void highfink::SetAll()
{
  abstr_emp::SetAll();
  std::cout << ">>Input number of abstr_emps managed: ";
  std::cin >> InChargeOf();
  while(std::cin.get() != '\n')
    continue;
  std::cout << ">>To whom fink reports: ";
  getline(std::cin, ReportsTo());
}
