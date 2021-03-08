
#include "_math/primes.h"
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <numeric>

//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

bool isPalindrome(size_t n)
{
  auto str = std::to_string(n);
  auto lit = str.begin();
  auto rit = str.rbegin();
  for(; lit != str.end(); ++lit, ++rit)
  {
    if(*lit != *rit)
    {
      return false;
    }
  }
  return true;
}


bool correctLength(int f, std::pair<size_t, size_t> const& limits)
{
  return f>=limits.first && f <=limits.second;
}

template<typename T>
T multiply(T a, T b)
{
  return a*b;
}

bool findFactors(size_t n, std::vector<size_t>&& factors, std::pair<size_t, size_t> const& fac_limits)
{
  if(factors.empty())
  {
    return false;
  }

  if(std::any_of(begin(factors), end(factors), [&](auto f) { return f > fac_limits.second; }))
  {
    return false;
  }

  std::vector<int> indexes;
  for(auto k = 0; k < factors.size(); ++k)
  {
    indexes.push_back(k);
  }


  do {
    for(auto pivot = 1; pivot < indexes.size(); ++pivot)
    {
      auto const it_pivot_l = std::next(begin(factors), pivot);
      auto const it_pivot_r = std::next(begin(factors), pivot);
      size_t const a = std::accumulate(begin(factors), it_pivot_l, 1, multiply<size_t>);
      size_t const b = std::accumulate(it_pivot_r, end(factors), 1, multiply<size_t>);
      if(a*b == n && correctLength(a, fac_limits) && correctLength(b, fac_limits))
      {
        std::cout << std::endl;
        std::cout << "nr: " << n << "\tf1: " << a << "\tf2: "<< b << std::endl;
        return true;
      }
    }
  } while(std::next_permutation(factors.begin(), factors.end()));
  return false;
}

void findLargestPalindrom(size_t start, std::pair<size_t, size_t> const& fac_limits)
{
  std::cout << "Calculating SPF" << std::endl;
  auto const& spf = SieveSPF(start);

  auto cnt = 0;
  for(auto n = start; n > static_cast<size_t>(std::sqrt(start)); --n)
  {
    if(!isPalindrome(n))
    {
      continue;
    }
    // if(cnt++%100 == 0) {
    //   std::cout << "Calculating the " << cnt << "th number" << std::endl;
    // }
    // std::cout << n << std::endl;
    auto const& factors_with_count = prime_factorisation_logn(n, spf);
    std::vector<size_t> factors;
    for(auto const& f : factors_with_count)
    {
      for(auto i = 0; i < f.second; ++i)
      {
        factors.push_back(f.first);
      }
    }

    if(findFactors(n, std::move(factors), fac_limits))
    {
      return;
    }
  }
}

int test()
{
  size_t const n = 6954596;
  auto const& spf = SieveSPF(10e6);
  auto const& factors_with_count = prime_factorisation_logn(n, spf);
  std::vector<size_t> factors;
  for(auto const& f : factors_with_count)
  {
    for(auto i = 0; i < f.second; ++i)
    {
      factors.push_back(f.first);
    }
  }
  findFactors(n, std::move(factors), std::make_pair(10,99));
  return 0;
}

int main()
{
  // return test();
  // findLargestPalindrom(10e3, std::make_pair(10,99));
  findLargestPalindrom(10e6, std::make_pair(100,999));
  return 0;
}