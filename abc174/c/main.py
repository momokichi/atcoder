k = int(input())

sevens = 7
ans = 1

if k % 2 == 0:
  print(-1)
  exit(0)

while True:
  print(sevens)
  if sevens % k == 0:
    print(ans)
    break
  sevens = sevens * 10 + 7
  ans = ans +1