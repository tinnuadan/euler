
#include "_math/primes.h"
#include <iostream>
#include <cmath>
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10 001st prime number?

void find_nth_prime(size_t n)
{
  auto const upper_bound = static_cast<size_t>(std::ceil(n * std::log(n) * 1.2));
  auto const primes = SieveOfEratosthenes(upper_bound);
  if(primes.size() < n+1)
  {
    std::cerr << "not enough numbers" << std::endl;
  }
  else
  {
    std::cout << primes.at(n) << std::endl;
  }
}

int main()
{
  find_nth_prime(10001);
  return 0;
}