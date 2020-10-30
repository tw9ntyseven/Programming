num = int(input())
s = [True for i in range(num + 1)]
x = 2

while x * x <= num:
    if s[x]:
        y = x * x
        while y <= num:
            s[y] = False
            y += x
    x += 1

if s[num]:
    print("Простое\n")
else:
    print("Составное\n")