n = int(input())
s = input()
result = 0

r = s.count('R')
g = s.count('G')
b = s.count('B')

result = r * g * b
count = 0

for i in range(n):
    for j in range(i, n):
        k = 2 * j - i
        if j < k < n:
            if s[i] != s[j] and s[i] != s[k] and s[j] != s[k]:
                count += 1

print(result-count)
