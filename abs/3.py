s = int(input())
count = 0
# print(s)

for i in range(3):
    if s % 10 == 1:
        count = count+1
    s = int(s/10)
    print(s)

print("{}".format(count))
