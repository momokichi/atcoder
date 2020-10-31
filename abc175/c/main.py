x, k, d = map(int, input().split())
if abs(d * k) <= abs(x):
  print(abs(x) - abs(d * k))
  exit(0)

if (k - (x / d) % 2 == 0):
  print(abs(abs(x) - abs(int(x/d) * k)))
else:
  print(abs(abs(x) - abs(int((x/d) +1) *k)))