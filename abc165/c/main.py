import itertools as it
n, m, q = map(int, input().split())
a = [0] * q
b = [0] * q
c = [0] * q
d = [0] * q

for i in range(q):
    a[i], b[i], c[i], d[i] = map(int, input().split())

A = list(it.combinations_with_replacement(list(range(1, m+1)), n))

max_list = [0] * len(A)
index = 0
for item in A:
    for i in range(q):
        if item[b[i]-1] - item[a[i]-1] == c[i]:
            max_list[index] += d[i]
    index += 1

# print(max_list)
print(max(max_list))
