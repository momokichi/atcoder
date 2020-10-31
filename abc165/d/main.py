#!/usr/bin/env Pypy3
import math
a, b, n = map(int, input().split())


def f(x):
    return math.floor((a*x)/b) - a * math.floor(x/b)


print(f(min(b-1, n)))
