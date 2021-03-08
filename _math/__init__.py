

def SieveOfEratosthenes(n):
  result = [1]
  isPrime = [True]*(n+1)
  isPrime[1] = False
  for i in range(2, n+1):
    if not isPrime[i]:
      continue
    # j*(i-1) is a factor of (i-1) and was covered before
    # Therefore start from i*i
    for j in range(i*i, n+1, i):
      if isPrime[j]:
        isPrime[j] = False
  for i in range(2, n+1):
    if isPrime[i]:
      result.append(i)
  return result