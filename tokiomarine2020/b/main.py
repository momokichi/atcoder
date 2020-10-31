a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())

flag = False

for i in range(1, t + 1):
    at = a + v * i
    bt = b + w*i
    if at == b:
        flag = True
        break
if flag:
    print("YES")
else:
    print("NO")
