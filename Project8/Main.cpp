#include "DynamicArray.h"
#include <iostream>

DynamicArray GetObj()
{
    DynamicArray obj(3);
    obj.Input();

    return obj;
}

int main()
{
    DynamicArray a(5);
    a.Input();
    a.Output();

    DynamicArray b = a;
    b.Output();

    DynamicArray result = GetObj();
    result.Output();

    DynamicArray rez = a + 10; 
    rez.Output(); 

    DynamicArray rez1 = a - 2;
    rez1.Output();

    DynamicArray rez2 = a * 2;
    rez2.Output();

    DynamicArray rez3 = a - b;
    rez3.Output();

    DynamicArray rez4 = a + b;
    rez4.Output();

    ++rez;
    rez.Output();

    --rez;
    rez.Output();

    return 0;

}