//
//  main.cpp
//  11
//
//  Created by Admin on 30.10.2020.
//

#include <iostream>

int64_t Elevate(int a, int b){
    int var = 1;
    int i = 0;
    
    while (i++ < b)
        var *= a;

    return var;
}

int main(){
    int num, pow;
    std::cin >> num >> pow;

    std::cout << Elevate(num, pow) << '\n';

    system("pause");
    return 0;
}
