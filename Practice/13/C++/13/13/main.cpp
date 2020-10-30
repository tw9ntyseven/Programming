//
//  main.cpp
//  13
//
//  Created by Admin on 30.10.2020.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    bool* s = new bool[n+1];
    memset(s, 1, sizeof(s));

    int x = 2;
    while (x * x <= n) {
        if (s[x]){
            for (int y = x * x; y <= n; y += x){
                s[y] = 0;
                x++;
            }
        }
    }

    if (s[n]) {
        std::cout << "Составное\n";
    } else {
        std::cout << "Простое\n";
    }

    delete[] s;
    return 0;
}
