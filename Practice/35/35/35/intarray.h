//
//  intarray.h
//  35
//
//  Created by Admin on 12.03.2021.
//

#ifndef intarray_h
#define intarray_h

#pragma once
struct IntArray
{
    int* data;
    int size;

    IntArray();
    IntArray(IntArray&);
    IntArray(const IntArray&);

    ~IntArray();


    void create(IntArray* arr, int size);
    void create(IntArray& arr, int size);
    
    int get(IntArray* arr, int index);
    int get(IntArray& arr, int index);
    
    void set(IntArray* arr, int index, int value);
    void set(IntArray& arr, int index, int value);
    
    void print(IntArray* arr);
    void print(IntArray& arr);
    
    void resize(IntArray* arr, int newSize);
    void resize(IntArray& arr, int newSize);

    void destroy(IntArray* arr);
    void destroy(IntArray& arr);
};

#endif /* intarray_h */
