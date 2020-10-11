import math;
print('Выберите способ ввода: 1 - через длины сторон; 2 - через координаты вершин', sep='')
count = int(input())

if count == 1:
    print('Введите длины сторон a, b, c', sep='')
    a = int(input())
    b = int(input())
    c = int(input())
    p = int((a + b + c)/2);
    s = int(math.sqrt(p * (p - a) * (p - b) * (p - c)));
    print('S = ', s, sep='');
    exit();
elif (count == 2):
    print('Введите координаты через пробел x y')
    x1, y1 = input().split()
    x2, y2 = input().split()
    x3, y3 = input().split()
    int(x1);
    int(x2);
    int(x3);
    int(y1);
    int(y2);
    int(y3);
    s1 = int((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)/2);
    print('S = ', s1, sep='');
    exit();
else: print('Неверный ввод!')

