// Writing my first C++ class: point on a plane

#include <iostream>

class point{

public:
  point(double a = 0.0, double b = 0.0) {x = a; y = b;}
  double getx() const {return x;}
  void setx(double v){x = v;}
  double gety() const {return y;}
  void sety(double v){y = v;}

private:
  double x, y;
};

point operator+ (point &p1, point &p2) {
  point sum(p1.getx() + p2.getx(), p1.gety() + p2.gety());
  return sum;
}

std::ostream& operator<< (std::ostream &out, point &p) {
  out << "(" << p.getx() << ", " << p.gety() << ")";
  return out;
}

int main() {
  point a(3.5, 2.5), b(2.5, 4.5), c;
  std::cout <<  "a = " << a << " b = " << b << std::endl;
  c = a + b;
  std::cout << "sum = " << c << std::endl;
}
