#include <iostream>
#include <cmath>

#include "_math/primes.h"

// The prime factors of 13195 are 5, 7, 13 and 29.

// What is the largest prime factor of the number 600851475143 ?

int main()
{
  size_t const n = 600851475143;
  // size_t const n = 13195;

  auto const max = static_cast<size_t>(std::sqrt(n));

  auto const& primes = SieveOfEratosthenes(max);

  for(auto it = std::prev(end(primes)); it != begin(primes); --it)
  {
    if(n%*it == 0)
    {
      std::cout << *it << std::endl;
      break;
    }
  }

  return 0;
}
