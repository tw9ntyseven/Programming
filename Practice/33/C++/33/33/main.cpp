//
//  main.cpp
//  33
//
//  Created by Admin on 03.03.2021.
//

#include <iostream>

void sort(int* arr, int n) {
    int i, key, j;
    
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int* create(int len, int base = 0, int step = 0) {
    if (len < 0) return nullptr;

    int* arr = new int[len];

    arr[0] = base;

    for (int i = 1; i < len; i++) {
        arr[i] = arr[i - 1] + step;
    }

    sort(arr, len);

    return arr;
}

void print(int* const arr, int len){
    if (len < 0) return;

    std::cout << '[';
    for (int i = 0; i < len - 1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[len - 1] <<']';
}

int main() {
    int len, base, step;
    std::cin >> len >> base >> step;

    int* arr = create(len, base, step);

    print(arr, len);

    delete[] arr;
    return 0;
}
