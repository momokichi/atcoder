n = int(input())
for b in range(1, 50):
    for a in range(1, 50):
        if (3 ** a > n) or (5 ** b > n):
            continue
        if (3 ** a) == n - (5**b):
            print(a, b)
            exit(0)
        # print(a, b)
        # print(3**a, 5**b)
        # print(3 ** a, n - (5 ** b))

print("-1")
