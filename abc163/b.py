N, M = input().split()
A = list(map(int,input().split()))

sum_a = sum(A)

if int(N)-sum_a>=0:
  print(int(N)-sum_a)
else:
  print(-1)