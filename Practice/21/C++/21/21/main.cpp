//
//  main.cpp
//  21
//
//  Created by Admin on 30.10.2020.
//

#include <iostream>

double bmi(double weight, double height) {
    height /= 100;
    return weight / (height * height);
}

void printBMI(double BMI) {
    if (BMI < 18.5) {
        std::cout << "Underweight";
    } else if (BMI >= 18.5 && BMI < 25.0) {
        std::cout << "Normal";
    } else if (BMI >= 25.0 && BMI < 30.0) {
        std::cout << "Overweight";
    } else if (30.0 <= BMI) {
        std::cout << "Obesity";
    }
}
int main() {
    double weight;
    std::cin >> weight;
    double height;
    std::cin >> height;
    
    printBMI(bmi(weight, height));

    return 0;
}
