a, b, c = ((int(x)) for x in input().split())

ans = 0

sa = (a * (a + 1) / 2) % 998244353
sb = (b * (b + 1) / 2) % 998244353
sc = (c * (c + 1) / 2) % 998244353

ans = (sa * sb * sc) % 998244353
print(int(ans) % 998244353)
