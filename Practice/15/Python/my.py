from random import randint
import random

print("--------------------------------Поробуй угадать число---------------------------------")
game_end = 1
s = 0

while game_end == 1:
    random.seed(s)
    num = randint(0, 100)
    check = 0

    for i in range(5):
        a = int(input())

        if num > a:
            print("Загаданное число больше")

        if num < a:
            print("Загаданное число меньше")

        if num == a:
            print("Поздравляю! Вы угадали")
            check = 1
            break

    if check != 1:
        print("Вы проиграли. Было загадано:", num, '\n')

    game_end = int(input("Хотите начать сначала? (1 - ДА )"))
    s += 1