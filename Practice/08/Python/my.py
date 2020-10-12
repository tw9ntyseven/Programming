a, b, c = input().split()
int(a)
int(c)
str(b)
if b == '+':
    d = int(a + c)
    print(int(d))
    exit()
elif b == '-':
    d = a - c
    print(d)
    exit()
elif b == '*':
    d = a * c
    print(d)
    exit()
elif b == '/':
    if c == 0:
        print('Неверный ввод!')
        exit();
    d = a / c
    print(d)
    exit
else: print('неверный ввод!')