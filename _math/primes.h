

#pragma once

#include <vector>
#include <array>
#include <optional>
#include <map>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>


std::vector<size_t> SieveSPF(size_t n)
{
  std::vector<size_t> result(n+1);
  // marking smallest prime factor for every 
  // number to be itself.
  size_t j = 0;
  std::generate(begin(result), end(result), [&j]() { return j++; });
  // and for even numbers to be two
  for(size_t i = 4; i<result.size(); i+=2)
  {
    result[i] = 2;
  }

  for(size_t i = 3; i*i <= n; ++i)
  {
    if(result[i] == i) // if it is a prime
    {
      // mark SPF for all numbers divisible by i 
      for(size_t j = i*i; j <= n; j+=i)
      {
        // if it was not previously marked
        if(result[j] == j)
        {
          result[j] = i;
        }
      }
    }
  }
  return result;
}

#if 0
std::vector<size_t> SieveOfEratosthenesSPF(size_t n)
{
  std::vector<size_t> result(n+1);
  result[0] = 1;
  result[1] = 1;
  std::vector<bool> isPrime(n+1, true);
  isPrime[0] = false;
  isPrime[1] = false;
  for(size_t i = 2; i <= n; ++i)
  {
    if(!isPrime[i])
    {
      continue;
    }
    // j*(i-1) is a factor of (i-1) and was covered before
    // Therefore start from i*i
    result[i] = i;
    for(size_t j = i*i; j <= n; j+=i)
    {
      if(isPrime[j])
      {
        isPrime[j] = false;
        result[j] = i;
      }
    }
  }
  return result;
}
#endif

std::vector<size_t> SieveOfEratosthenes(size_t n)
{
  std::vector<size_t> result{1};
  std::vector<bool> isPrime(n+1);
  std::fill(isPrime.begin(), isPrime.end(), true);
  isPrime[0] = false;
  isPrime[1] = false;
  for(size_t i = 2; i <= n; ++i)
  {
    if(!isPrime[i])
    {
      continue;
    }
    for(size_t j = i*i; j <= n; j+=i)
    {
      if(isPrime[j])
      {
        isPrime[j] = false;
      }
    }
  }
  for(size_t i = 2; i <= n; ++i)
  {
    if(isPrime[i])
    {
      result.push_back(i);
    }
  }
  return result;
}


std::map<size_t, size_t> prime_factorisation_logn(size_t n, std::vector<size_t> const& SPF)
{
  std::map<size_t, size_t> result;
  auto const orig = n;
  while(n != 1)
  {
    auto p = SPF[n];
    auto count = 0;
    while(n%p == 0)
    {
      n /= p;
      ++count;
    }
    if(n == orig)
    {
      return result; // n is a prime
    }
    result.emplace(p, count);
  }
  return result;
}


void saveSPF(std::vector<size_t> const& spf, std::string const& filename)
{
  std::ofstream fout(filename);
  for(auto const& f : spf)
  {
    fout << f << ",";
  }
  fout.close();
}

std::vector<size_t> loadSPF(std::string const& filename)
{
  std::vector<size_t> result;
  std::ifstream fin(filename);
  size_t i;
  char c;
  while(!fin.eof())
  {
    fin >> i >> c;
    result.push_back(i);
  }
  fin.close();
  return result;
}


// #define MAX 892
// size_t SPF[MAX];
// void sieve(size_t n=MAX) {
//     bool isPrime[n+1];
//     for (size_t i=1; i<=n; i++) isPrime[i] = 1;
//     isPrime[1] = 0;
//     for (size_t i=2; i<=n; i++) {
//         // assert isPrime == True
//         if (!isPrime[i]) continue;
//         /* j*(i-1) is a factor of (i-1) and was covered before
//            Therefore start from i*i */
//         SPF[i] = i;
//         for (size_t j=i*i; j<=n; j+=i)
//             if (isPrime[j]) isPrime[j] = 0, SPF[j] = i;
//     }
// }
// vector<pair<size_t, size_t> > prime_factorisation_logn(size_t n) {
//     vector<pair<size_t, size_t> > pf;
//     while (n!=1) {
//         size_t p = SPF[n], count = 0;
//         while (n%p==0) n/=p, ++count;
//         pf.push_back({p, count});
//     }
//     return pf;
// }