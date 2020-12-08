//
//  main.cpp
//  25
//
//  Created by Admin on 08.12.2020.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> bozoSort(std::vector<int> arr, bool bl=1) {
    bool c = 1;
    while (c) {
        long r1 = rand() * arr.size() / RAND_MAX; long r2 = rand() * arr.size() / RAND_MAX;
        int tmp = arr[r1];
        arr[r1] = arr[r2];
        arr[r2] = tmp;

        if (bl) {
            bool tmpBool = 1;
            for (auto i = arr.begin(); i != arr.end() - 1; i++) {
                if (*i > *(i + 1)) {
                    tmpBool = 0;
                    break;
                }
            }
            c = !tmpBool;
        } else {
            bool tmpBool = 1;
            for (auto i = arr.begin(); i != arr.end() - 1; i++) {
                if (*i < *(i + 1)) {
                    tmpBool = 0;
                    break;
                }
            }
            c = !tmpBool;
        }
    }

    return arr;
}

std::vector <std::vector<int>> bozoSort(std::vector<std::vector<int>> arr, bool bl = 1) {
    const int m = arr.size();
    const int n = arr[0].size();

    bool c = 1;
    while (c) {
        int r11 = rand() * n / RAND_MAX;
        int r12 = rand() * m / RAND_MAX;
        int r21 = rand() * n / RAND_MAX;
        int r22 = rand() * m / RAND_MAX;

        int tmp = arr[r12][r11];
        arr[r12][r11] = arr[r22][r21];
        arr[r22][r21] = tmp;
        
        if (bl) {
            bool tmpBool = 1;
            int previousNumber = arr[0][0];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (previousNumber > arr[i][j]) {
                        tmpBool = 0;
                    }
                    previousNumber = arr[i][j];
                }
            }
            c = !tmpBool;
        } else {
            bool tmpBool = 1;
            int previousNumber = arr[0][0];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (previousNumber < arr[i][j]) {
                        tmpBool = 0;
                    }
                    previousNumber = arr[i][j];
                }
            }
            c = !tmpBool;
        }
    }

    return arr;
}

std::vector<int> bozoSort(int a, int b, int c, bool bl = 1) {
    std::vector<int> arr;
    
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    return bozoSort(arr, bl);
}

void printVector(std::vector<int> vec) {
    for (auto i = vec.begin(); i != vec.end(); i++) {
        std::cout << *i << ' ';
    }
    std::cout << '\n';
}

void printVector(std::vector<std::vector<int>> vec) {
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec[i].size(); j++) {
            std::cout << vec[i][j] << ' ';
        }
    }
    std::cout << '\n';
}


int main() {
    srand(time_t(NULL));
    int n;
    std::cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }

    auto arr11 = bozoSort(arr1);
    auto arr12 = bozoSort(arr1, 0);

    printVector(arr11);
    printVector(arr12);

    int m = sqrt(n);
    std::vector<std::vector<int>> arr2(m, std::vector<int>(m));

    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            arr2[i][j] = arr[k++];
        }
    }
    auto arr21 = bozoSort(arr2);
    auto arr22 = bozoSort(arr2, 0);
    printVector(arr21);
    printVector(arr22);

    int a = arr[0];
    int b = arr[1];
    int c = arr[2];

    auto arr_3_1 = bozoSort(a, b, c);
    auto arr_3_2 = bozoSort(a, b, c, 0);

    printVector(arr_3_1);
    printVector(arr_3_2);


    delete[] arr;
    return 0;
}
