N =int(input())
A = list(map(int, input().split()))
result = [0]*(len(A)+1)

for i in range(len(A)):
  result[A[i]-1]+=1

for i in range(len(result)):
  print(result[i])