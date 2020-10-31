N = int(input())
a = list(map(int, input().split()))
alice_point, bob_point = 0, 0

a.sort()
a.reverse()

for i in range(0, N, 2):
    alice_point += a[i]
for j in range(1, N, 2):
    bob_point += a[j]

print(alice_point - bob_point)
