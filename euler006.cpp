#include <iostream>
#include <vector>

// The sum of the squares of the first ten natural numbers is,

// The square of the sum of the first ten natural numbers is,

// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is

// .

// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

size_t calcDiff(size_t max)
{
  std::vector<size_t> numbers(max);
  for(size_t i = 1; i<= max; ++i)
  {
    numbers.push_back(i);
  }

  //(a+b+c+...n)^2 = 2ab + 2ac + 2bc + ... 2an + 2cn + 2(n-1)n

  size_t result = 0;
  for(auto it1 = begin(numbers); std::next(it1) != end(numbers); ++it1)
  {
    for(auto it2 = std::next(it1); it2 != end(numbers); ++it2)
    {
      result += 2 * (*it1) * (*it2);
    }
  }
  return result;
}

int main()
{
  std::cout << calcDiff(10) << std::endl;
  std::cout << calcDiff(100) << std::endl;
}