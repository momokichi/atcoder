import math
N=int(input())
R=0

def gcd_3(a,b,c):
  return math.gcd(math.gcd(a,b), c)

for a in range(1,N+1):
  for b in range(1,N+1):
    for c in range(1,N+1):
      R+=gcd_3(a,b,c)

print(R)