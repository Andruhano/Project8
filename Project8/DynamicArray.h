#pragma once
#include <iostream>

class DynamicArray
{
    int* ptr;
    int size;

public:
    DynamicArray();
    DynamicArray(int);
    DynamicArray(const DynamicArray&);
    ~DynamicArray();

    void Input();
    void Output() const;
    int* GetPointer() const;
    int GetSize() const;

    DynamicArray operator+(int value);
    DynamicArray operator-(int count);
    DynamicArray operator*(int factor);
    DynamicArray operator-(const DynamicArray& other);
    DynamicArray operator+(const DynamicArray& other);
    DynamicArray& operator++();
    DynamicArray& operator--();
};
