N, A, B = map(int, input().split())
result = 0

for i in range(N+1):
    tmp = str(i)
    sum = 0
    for j in range(len(tmp)):
        sum += int(tmp[j])
    if sum >= A and sum <= B:
        result += i

print(result)
