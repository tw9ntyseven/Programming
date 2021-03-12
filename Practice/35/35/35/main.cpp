//
//  main.cpp
//  35
//
//  Created by Admin on 12.03.2021.
//

#include <iostream>
#include "intarray.h"

IntArray::IntArray()
    : data(nullptr), size(0) {}

IntArray::IntArray(IntArray& other)
    : data(other.data), size(other.size){}

IntArray::IntArray(const IntArray& other)
    : data(other.data), size(other.size){}

IntArray::~IntArray(){
    delete[] data;
}

void IntArray::create(IntArray& arr, int size){
    if (size < 0) return;

    arr.data = new int[size];
    arr.size = size;
}

void IntArray::create(IntArray* arr, int size) {
    create(*arr, size);
}

int IntArray::get(IntArray& arr, int index) {
    if (index < 0 || index >= arr.size) {
        std::cerr << "Index out of range!";
    } else {
        return arr.data[index];
    }
}

int IntArray::get(IntArray* arr, int index){
    return get(*arr, size);
}

void IntArray::set(IntArray& arr, int index, int value){
    if (index < 0 || index >= arr.size) {
        std::cerr << "Index out of range!";
    } else {
        arr.data[index] = value;
    }
}

void IntArray::set(IntArray* arr, int index, int value) {
    set(*arr, index, value);
}

void IntArray::print(IntArray& arr) {
    if (arr.size < 0) return;

    std::cout << '[';

    for (int i = 0; i < arr.size - 1; i++) {
        std::cout << arr.data[i] << ", ";
    }
    
    std::cout << arr.data[arr.size - 1] << ']';
}

void IntArray::print(IntArray* arr){
    print(*arr);
}

void IntArray::resize(IntArray& arr, int newSize){
    if (newSize < 0 || newSize == arr.size)
        return;

    int* tmp_arr = new int[newSize];
    memset(tmp_arr, 0, sizeof(arr.data) * newSize);

    for (int i = 0; i < newSize; i++) {
        tmp_arr[i] = arr.data[i];
    }

    if (arr.data != nullptr) {
        delete[] arr.data;
    }
    
    arr.data = tmp_arr;

    delete[] tmp_arr;
}

void IntArray::resize(IntArray* arr, int newSize) {
    resize(*arr, newSize);
}

void IntArray::destroy(IntArray& arr) {
    if (arr.data == nullptr && arr.size == 0)
        return;

    delete[] arr.data;
    arr.data = nullptr;

    arr.size = 0;
}

void IntArray::destroy(IntArray* arr) {
    destroy(*arr);
}
