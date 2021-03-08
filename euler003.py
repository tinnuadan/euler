from _math import SieveOfEratosthenes
from math import sqrt

n = 600851475143
#n = 13195

max = int(sqrt(n))+1
primes = SieveOfEratosthenes(max)

#primes = list(reversed(primes))
for p in reversed(primes):
  if n%p == 0:
    print(p)
    break