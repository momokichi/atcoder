a,b, c, d = [int(x) for x in input().split()]

while a>0 or c>0:
  c -=b
  if c <=0:
    print("Yes")
    break
  a-=d
  if a<=0:
    print("No")
    break