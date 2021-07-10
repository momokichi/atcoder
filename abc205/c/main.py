a, b, c = map(int, input().split())


def pow(x, n):
    ret = 1
    while n > 0:
        if n % 2:
            ret *= x
        x *= x
        n >>= 1
    return ret


if pow(a, c) > pow(b, c):
    print('>')
elif pow(a, c) < pow(b, c):
    print('<')
else:
    print('=')
