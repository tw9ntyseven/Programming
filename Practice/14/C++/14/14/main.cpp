//
//  main.cpp
//  14
//
//  Created by Admin on 30.10.2020.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    std::cout << "---------------------Поробуй угадать число-------------------------\n";

A:
    // Random time
    int n = rand() % 100 + 1;

    int a;
    bool res = true;
    int t = -4;

    for (int i = 0; i < 5; i++) {
        std::cin >> a;

        if (a < n && t) {
            std::cout << "Загаданное число больше\n";
        }
        if (a > n && t) {
            std::cout << "Загаданное число меньше\n";
        }
        if (a == n && t) {
            std::cout << "Поздравляю! Вы угадали\n";
            res = false;
            break;
        }
        t++;
    }
    if (res) {
        std::cout << "Вы проиграли. Было загадано:" << n << '\n';
    }

    int c = 0;
    std::cout << "Хотите начать сначала? (1 - ДА )";
    std::cin >> c;

    if (c == 1) {
        goto A;
    }
    return 0;
}
