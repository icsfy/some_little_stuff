#ifndef COMPLEX0_H
#define COMPLEX0_H

class complex
{
  private:
    double x;
    double y;
  public:
    complex(const double a=0.0, const double b=0.0);
    ~complex();
    complex operator~() const;
    complex operator+(const complex & c) const;
    complex operator-() const;
    complex operator-(const complex & c) const;
    complex operator*(const complex & c) const;
    friend complex operator*(double n, const complex & c);
    friend std::ostream & operator<<(std::ostream & os, const complex & c);
    friend std::istream & operator>>(std::istream & is, complex & c);
};

#endif

#ifndef COMPLEX0_C
#define COMPLEX0_C
complex::complex(const double a, const double b)
{
  x = a;
  y = b;
}
complex::~complex()
{
}
complex complex::operator~() const
{
  return complex(x, -y);
}
complex complex::operator+(const complex & c) const
{
  complex sum;
  sum.x = x + c.x;
  sum.y = y + c.y;
  return sum;
}
complex complex::operator-() const
{
  return complex(-x, -y);
}
complex complex::operator-(const complex & c) const
{
  complex diff;
  diff.x = x - c.x;
  diff.y = y - c.y;
  return diff;
}
complex operator*(double n, const complex & c)
{
  return complex(n) * c;
}
complex complex::operator*(const complex & c) const
{
  complex result;
  result.x = x * c.x - y * c.y;
  result.y = x * c.y + y * c.x;
  return result;
}
std::ostream & operator<<(std::ostream & os, const complex & c)
{
  os << "(" << c.x << "," << c.y << "i)";
  return os;
}
std::istream & operator>>(std::istream & is, complex & c)
{
  cout << "real: ";
  if(!(is >> c.x))
    return is;
  cout << "imaginary: ";
  is >> c.y;
  return is;
}
#endif
