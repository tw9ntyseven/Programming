//
//  main.cpp
//  01
//
//  Created by Admin on 19.09.2020.
//  Copyright © 2020 Vlad. All rights reserved.
//

#include <iostream>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    a = 2 + 2 * 2;
    std::cout << "Результат выражения 2+2*2 = " << a << endl;
 }
