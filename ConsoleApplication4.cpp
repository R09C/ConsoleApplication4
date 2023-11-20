// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "BoolVector.h"
int main() {
    // 1) Создание объектов BoolVector и вывод на консоль
    BoolVector B1;
    BoolVector B2(10);
    char s[] = "111011101110";
    BoolVector B3(s);
    BoolVector B4(s, 10);
    BoolVector B5(s, 16);

    cout << "B1: " << B1 << endl;
    cout << "B2: " << B2 << endl;
    cout << "B3: " << B3 << endl;
    cout << "B4: " << B4 << endl;
    cout << "B5: " << B5 << endl;

    // 2) Нахождение веса B3 и B5, проверка на равенство
    int weight_B3 = B3.Weight();
    int weight_B5 = B5.Weight();
    cout << "Weight of B3: " << weight_B3 << endl;
    cout << "Weight of B5: " << weight_B5 << endl;
    cout << "B3 == B5: " << (B3 == B5) << endl;

    // 3) Создание вектора B6, инициализация
    BoolVector B6 = B5;
    cout << "B5: " << B5 << endl;
    cout << "B6: " << B6 << endl;

    // 4) Инициалифзация B2 с клавиатуры
    cout << "Enter a binary vector for B2 (e.g., 1001100111): ";
    B2.Scan();
    cout << "B2: " << B2 << endl;

    // 5) Инициализация B1 вектором B2, вывод и сравнение
    B1 = B2;
    cout << "B1: " << B1 << endl;
    cout << "B1 == B2: " << (B1 == B2) << endl;

    // 6) Побитовые операции и вывод
    BoolVector V1 = B1 & B3;
    BoolVector V2 = B1 | B3;
    BoolVector V3 = B1 ^ B3;
    cout << "V1 (B1 & B3): " << V1 << endl;
    cout << "V2 (B1 | B3): " << V2 << endl;
    cout << "V3 (B1 ^ B3): " << V3 << endl;

    // 7) Побитовое И и сравнение
    cout << "B1 &= B3: " << (B1 &= B3) << endl;
    cout << "B1 == V1: " << (B1 == V1) << endl;

    // 8) Побитовое ИЛИ и сравнение
    cout << "B2 |= B3: " << (B3 |= B2) << endl;
    cout << "B2 == V2: " << (B3 == V2) << endl;

    // 9) Инвертирование и доступ к битам
    cout << "B1: " << B1 << endl;
    cout << "B1[4]: " << B1[4] << endl;
    cout << "B1[5]: " << B1[5] << endl;
    B1.Invert();
    cout << "B1: " << B1 << endl;


    // 10) Установка, сброс и инвертирование битов
    B1.SetUp0(7);
    cout << "Modified B1: " << B1 << endl;
    B1.Invert(9);
    cout << "Modified B1: " << B1 << endl;

    // 11) Установка и инвертирование группы битов
    B1.SetUp1(3, 5);
    cout << "Modified B1: " << B1 << endl;
    B1.Invert(3, 1);
    cout << "Modified B1: " << B1 << endl;

    // 12) Сдвиг влево и сравнение
    char s5[] = "1111110111";
    BoolVector B7(s5);
    BoolVector V4 = B7 << 4;
    cout << "V4 (B1 << 4): " << V4 << endl;
    B7 >>= 4;
    
    cout << "B1 == V4: " << (B7 == V4) << endl;

    return 0;
}