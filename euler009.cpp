#include <iostream>

// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a^2 + b^2 = c^2

// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

// euclids formula
// given m>n>0
// a = m^2 - n^2, b = 2mn, c=m^2+n^2

// given a+b+c == 1000 --> m^2 + mn = 500

int main()
{
  for(int n=2; n<=250; ++n)
  {
    for(int m=n+1; m<250; ++m)
    {
      auto const s = m*(m+n);
      if(s>500)
      {
        break;
      }
      if(s == 500)
      {
        auto const a = m*m - n*n;
        auto const b = 2*m*n;
        auto const c = m*m + n*n;
        std::cout << a << "^2 + " << b << "^2 = " << c << "^2"  <<          std::endl;
        std::cout << a << " + "   << b << " + "   << c << " = " << a+b+c << std::endl;
        std::cout << a << " * "   << b << " * "   << c << " = " << a*b*c << std::endl;
      }
    }
  }
  return 0;
}