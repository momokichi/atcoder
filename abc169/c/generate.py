#!/usr/bin/env python3
import random
N = random.randint(1, 100)
W = random.randint(1, 10000)
print(N, W)
for _ in range(N):
    v = random.randint(0, 10**15)
    w = random.uniform(0, 10)
    print(v, w)
