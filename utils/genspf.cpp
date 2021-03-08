#include "_math/primes.h"

int main()
{
  auto const& spf = SieveSPF(10e6);

  saveSPF(spf, "spf10e6.txt");

  return 0;
}