#!/usr/bin/env python3
n, k = map(int, input().split())

num = set()

for i in range(k):
  d = int(input())
  tmp = [int(x) for x in input().split()]
  for j in range(d):
    num.add(tmp[j])
  # print(num)

print(n- len(num))