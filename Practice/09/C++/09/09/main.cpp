//
//  main.cpp
//  09
//
//  Created by Admin on 29.10.2020.
//

#include <iostream>

int main() {
    int h1,m1,h2,m2;
    std::cout << "Введите час потом минуты, первого и второго человека\n";
    std::cin >> h1 >> m1 >> h2 >> m2;
    if(0 <= h1 && h1 <= 23 && 0 <= m1 && m1 <= 59 && 0 <= h2 && h2 <= 23 && 0<= m2 && m2 <= 59){
        int a = h1 + m1;
        int b = h2 + m2;
        int c = a - b;
        if(c <= 15 && c >= -15){
            std::cout << "Встреча состоится!\n";
            return 0;
        } else {
            std::cout << "Встреча не состоится!\n";
        }
    } else {
        return main();
    }
    return 0;
}
