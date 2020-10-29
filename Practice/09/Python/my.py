h1, b, m1 = input().split()
h2, b, m2 = input().split()
int(h1)
int(h2)
int(m1)
int(m2)
str(b)
if b == ':':
    d = int(h1 + m1)
    d1 = int(h2 + m2)
    res = d - d1
    if res <= 15 & res >= -15:
        print('Встреча состоится')
        exit()
    else:
        print('Встреча не состоится')
        exit()
else: print('Неверный ввод!')
    