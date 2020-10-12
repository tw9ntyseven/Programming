//
//  main.cpp
//  08
//
//  Created by Admin on 12.10.2020.
//

#include <iostream>

int main() {
    int a, c, d;
    char b;
    std::cin >> a >> b >> c;
    if (b == '+') {
        d = a + c;
        std::cout << d << std::endl;
        return 0;
    } else if (b == '-') {
        d = a - c;
        std::cout << d << std::endl;
        return 0;
    } else if (b == '*') {
        d = a * c;
        std::cout << d << std::endl;
        return 0;
    } else if (b == '/') {
        if (c == 0){
            std::cout << "Неверный ввод!" << std::endl;
            return main();
        }
        d = a / c;
        std::cout << d << std::endl;
        return 0;
    }
}
