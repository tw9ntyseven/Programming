//
//  main.cpp
//  12
//
//  Created by Admin on 30.10.2020.
//

#include <iostream>

int Fact(int a) {
    if (a > 1) {
        return Fact(a - 1) * a;
    } else {
        return 1;
    }
}

int main() {
    int num;
    std::cin >> num;
    std::cout << Fact(num) << '\n';

    system("pause");
    return 0;
}
