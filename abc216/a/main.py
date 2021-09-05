s = input()

a = s.split('.')

if int(a[1]) <= 2:
    print(str(a[0]) + "-")
elif int(a[1]) <=6:
    print(str(a[0]))
else:
    print(str(a[0])+"+")