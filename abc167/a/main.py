#!/usr/bin/env python3

s = input()
t = input()

if(t.startswith(s) and len(t) == len(s)+1):
    print("Yes")
else:
    print("No")
