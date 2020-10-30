//
//  main.cpp
//  16
//
//  Created by Admin on 30.10.2020.
//

#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    bool x = 0;
    std::vector<std::string> vector;
    std::string * arr = new std::string[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 'a' && arr[i][8] == '1' && arr[i][7] == '6' && arr[i][6] == '6' && arr[i][5] == '5' && arr[i][4] == '5') {
            vector.push_back(arr[i]);
            x = 1;
        }
    }
    if (x) {
        for (auto i = vector.begin(); i < vector.end(); i++){
            std::cout << * i << ' ';
        }
    } else {
        std::cout << "-1\n";
        }
    delete[] arr;
    return 0;
}
