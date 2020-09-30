print("Введите 3 вещественных числа\n")
float(input(a))
float(input(b))
float(input(c))

if a == 0 | b == 0 | c == 0:
    print("Числа не могут быть равны 0!\n")
    break

d = b * b - 4 * a * c
if d < 0:
    print("Корней нет!")
    sys.exit(0)
elif d == 0:
    x = (-1 * b) / (2 * a)
    print("Корень один x =", x)
    sys.exit(0)

x1 = (-1 * b + sqrt(d)) / (2 * a)
x2 = (-1 * b - sqrt(d)) / (2 * a)

print("x1 = ", x1, "x2 = ", x2);

