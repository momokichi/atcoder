#!/usr/bin/env python3
n, m = map(int, input().split())
h = [int(x) for x in input().split()]
a = [0]* m
b  =[0]* m

for i in range(m):
  a[i], b[i]= map(int, input().split())

ans = 0
for i in range(n):
  hoge = True
  if not((i+1) in a or (i+1) in b):
    continue
  for j in range(m):
    if i+1 == a[j]:
      if h[i] <= h[b[j]-1]:
        hoge = False
        break
    elif i+1 == b[j]:
      if h[i] <=h[a[j]-1]:
        hoge = False
        break
  if hoge:
    ans +=1

print(ans)