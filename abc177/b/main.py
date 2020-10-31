#!/usr/bin/env python3
s = input()
t = input()

max = 0

for i in range(1, len(t)+1):
  if t[i:] in s:
    print(len(t) - i)
    break


