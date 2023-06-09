// 2222.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "MyArray.h"
#include <clocale>

#include <algorithm>
using namespace std;

int main()
{
    MyArray test1(5);
    MyArray test2(5);
    
    test1.Initialize();
    test2.Initialize();
    MyArray test3 = test1 - test2;
    
    test3.Show();
    
}