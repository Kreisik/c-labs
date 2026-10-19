// Бондаренко Степан 621704 | Лаба 2 | 3 Вариант | 14.09.2026

#include <stdio.h>

double GetMax(double a, double b) { // Функция для нахождения минимального значения

    if (a > b) {
        return a;
    } else {
        return b;
    }

}

double GetMin(double a, double b) { // Функция для нахождения максимального значения

    if (a < b) {
        return a;
    } else {
        return b;
    }

}

int main() {

    double x, y, z;
    printf("Enter x, y, z: ");

    if (scanf("%lf %lf %lf", &x, &y, &z) != 3) { // Проверка ввода числового/нечислового значения

        printf("Incorrect type");
        return 1;

    }

        double sum = x + y + z;
        double prod = x * y * z;

        double max_value = GetMax(sum, prod);
        double min_value = GetMin(sum, prod);

        if (min_value == 0) { // Проверка деления на 0

            printf("Divide to zero incorrect");
            return 1;

        } else {

            double result = max_value / min_value; // Вычисление результата
            printf("Result: %f", result);
        }

    return 0;
}