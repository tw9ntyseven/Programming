//
//  main.cpp
//  04 C++
//
//  Created by Admin on 23.09.2020.
//

#include <iostream>

int main() {
    int a, b, buf;
    std::cin >> a >> b;
    buf = a;
    a = b;
    b = buf;
    std::cout << a << std::endl << b << std::endl;
    
    int c, d;
    std::cin >> c >> d;
    c = c + d;
    d = c - d;
    c = c - d;
    std::cout << c << std::endl << d << std::endl;
    return 0;
}
