//
//  main.cpp
//  03 C++
//
//  Created by Admin on 22.09.2020.
//  Copyright © 2020 Vlad. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int a, b, resPlus, resMinus, resMultiply, resSplit;
    
    std::cout << "Введите для типа int" << std::endl;
    std::cin >> a >> b;
    
    resPlus = a + b;
    resMinus = a - b;
    resMultiply = a * b;
    resSplit = a / b;
    
    std::cout << "Сложение: " << resPlus << "\nВычитание: " << resMinus<< "\nУмножение: " << resMultiply<< "\nДеление: " << resSplit << std::endl;
    
    double c, d, doublePlus, doubleMinus, doubleMultiply, doubleSplit;
    
    std::cout << "Введите для тип double" << std::endl;
    std::cin >> c >> d;
    
    doublePlus = c + d;
    doubleMinus = c - d;
    doubleMultiply = c * d;
    doubleSplit = c / d;
    
    std::cout << "Сложение: " << doublePlus << "\nВычитание: " << doubleMinus << "\nУмножение: " << doubleMultiply << "\nДеление: " << doubleSplit << std::endl;
    
    int f;
    double e, diPlus, diMinus, diMultiply, diSplit;
    
    std::cout << "Введите для тип double int" << std::endl;
    std::cin >> e >> f;
    
    diPlus = c + d;
    diMinus = c - d;
    diMultiply = c * d;
    diSplit = c / d;
    
    std::cout << "Сложение: " << diPlus << "\nВычитание: " << diMinus << "\nУмножение: " << diMultiply << "\nДеление: " << diSplit << std::endl;
    
    int g;
    double h, idPlus, idMinus, idMultiply, idSplit;
    
    std::cout << "Введите для тип int double" << std::endl;
    std::cin >> g >> h;
    
    idPlus = c + d;
    idMinus = c - d;
    idMultiply = c * d;
    idSplit = c / d;
    
    std::cout << "Сложение: " << idPlus << "\nВычитание: " << idMinus << "\nУмножение: " << idMultiply << "\nДеление: " << idSplit << std::endl;
}
