#include "DynamicArray.h"
#include <Windows.h>
using namespace std;

DynamicArray::DynamicArray() : ptr(nullptr), size(0)
{}

DynamicArray::DynamicArray(int S)
{
    cout << "Construct by 1 param\n";
    size = S;
    ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray& a)
{
    cout << "Copy construct\n";
    size = a.size;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        ptr[i] = a.ptr[i];
    }
}

DynamicArray::~DynamicArray()
{
    cout << "Destruct\n";
    if (ptr != 0)
    {
        delete[] ptr;
    }
    Sleep(1000);
}

void DynamicArray::Input()
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 20;
    }
}

void DynamicArray::Output() const
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << "\n---------------------------------\n";
}

int* DynamicArray::GetPointer() const
{
    return ptr;
}

int DynamicArray::GetSize() const
{
    return size;
}

DynamicArray DynamicArray::operator+(int value)
{
    DynamicArray result(size + value);
    for (int i = 0; i < size; ++i)
    {
        result.ptr[i] = ptr[i];
    }
    return result;
}

DynamicArray DynamicArray::operator-(int count)
{
    DynamicArray result(size - count);
    for (int i = 0; i < result.size; ++i)
    {
        result.ptr[i] = ptr[i];
    }
    return result;
}

DynamicArray DynamicArray::operator*(int factor)
{
    DynamicArray result(size);
    for (int i = 0; i < size; ++i)
    {
        result.ptr[i] = ptr[i] * factor;
    }
    return result;
}

DynamicArray DynamicArray::operator-(const DynamicArray& other)
{
    DynamicArray result(size);
    for (int i = 0; i < size; ++i)
    {
        result.ptr[i] = ptr[i] - other.ptr[i];
    }
    return result;
}

DynamicArray DynamicArray::operator+(const DynamicArray& other)
{
    DynamicArray result(size + other.size);
    for (int i = 0; i < size; ++i)
    {
        result.ptr[i] = ptr[i];
    }
    for (int i = 0; i < other.size; ++i)
    {
        result.ptr[size + i] = other.ptr[i];
    }
    return result;
}

DynamicArray& DynamicArray::operator++()
{
    int* newPtr = new int[size + 1];
    for (int i = 0; i < size; ++i)
    {
        newPtr[i] = ptr[i];
    }
    delete[] ptr;
    ptr = newPtr;
    ++size;
    return *this;
}

DynamicArray& DynamicArray::operator--()
{
    int* newPtr = new int[size - 1];
    for (int i = 0; i < size - 1; ++i)
    {
        newPtr[i] = ptr[i];
    }
    delete[] ptr;
    ptr = newPtr;
    --size;
    return *this;
}
