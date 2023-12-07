#include <stdio.h>
#include <iostream>

int main()
{

    setlocale(LC_ALL, "Russian");

    float array[100];
    int n=0;
    float sum=0, kol = 0.0, res;

    do {
        printf("Введите количество чисел в массиве, не больше 100 элементов: ");
        scanf_s("%i", &n);
    } while (n <= 0);


    // Цикл для заполнения массива значениями
    for (int i = 0; i < n; i++) {
        printf("Введите %i элемент массива: ", i + 1);
        scanf_s("%f", &array[i]);
    }

    for (int i = 1; i < n; i += 2) {
        sum = sum + array[i];
        kol++;
    };
    res = sum / kol;
    printf("%f", res);
}