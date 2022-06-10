// Simple way of dealing with days as enums

#include <iostream>
// using namespace :: std;

typedef enum days{SUN, MON, TUE, WED, THU, FRI, SAT} days;

// Inlining the overloading of the ++ operator because we expect
// to do this often and inlining can make things like this more
// efficient
// Passing this dummy int here means this is the post increment ++
// Not passing the dummy means you use the pre increment
inline days operator++ (days d, int)
{
  return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

// Not inlining this operator overloading because we might not
// use it as often.
std::ostream& operator<< (std::ostream& out, const days& d)
{
  switch(d)
  {
    case SUN: out << "SUN"; break;
    case MON: out << "MON"; break;
    case TUE: out << "TUE"; break;
    case WED: out << "WED"; break;
    case THU: out << "THU"; break;
    case FRI: out << "FRI"; break;
    case SAT: out << "SAT"; break;
  }
  return out;
}

int main()
{
  days d = MON, e;
  e = d++;
  std::cout << d << '\t' << e << std::endl;
}
