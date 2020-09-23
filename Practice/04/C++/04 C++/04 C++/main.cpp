//
//  main.cpp
//  04 C++
//
//  Created by Admin on 23.09.2020.
//

#include <iostream>

int main() {
    int x0, v0, t, res;
    double g;
    std::cout << "Введите x0 v0 t" << std::endl;
    std::cin >> x0 >> v0 >> t;
    g = 9.8;
    
    res = x0 + v0 * t - g*t*t/2;
    
    std::cout << res << std::endl;
    return 0;
}
