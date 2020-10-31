N = int(input())
A=list(map(int,input().split()))
count = 0

def isAllNumEven(list):
  for i in range(N):
    if list[i]%2!=0:
      return False
  return True

while isAllNumEven(A):
  A=list(map(lambda x: x/2,A))
  count+=1

print(count)