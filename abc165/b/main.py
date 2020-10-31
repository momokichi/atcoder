x = int(input())
s = float(100.0)
count = 0

while s < x:
    s = int(s*1.01)
    # print(s)
    count += 1

print(count)
