

limit = 1000

sum = 0

for i in range(1, 334):
  n = 3*i
  if n < limit:
    sum += n
  else:
    break

for i in range(1, 200):
  n = 5*i
  if n < limit:
    if n%3!=0:
      sum += n
  else:
    break

print(sum)