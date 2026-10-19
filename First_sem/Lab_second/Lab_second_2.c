// Бондаренко Степан 621704 | Лаба 2 | 3 Вариант | 14.09.2026

#include <math.h>
#include <stdio.h>


int main() {
    int function;
    double result;
    double x, a, b, z;
    printf("Enter a, b, z: ");

    if (scanf("%lf %lf %lf", &a, &b, &z) != 3) { // Проверка на ввод 3 чисел

        printf("Incorrect type\n");
        return 1;

    }

    printf("1 - 2x, 2 - x^2, 3 - x / 3: ");
    if (scanf("%d", &function) != 1 || function < 1 || function > 3) { // Проверка на корректность ввода переменной function(1-3)
        return 1;
    }

    if (z < 1) { // Проверка переменной z
        x = z;
    } else {
        x = sqrt(pow(z, 3));
    }

    double first_part;
    double second_part = a * pow(cos(pow(x, 3)), 2);
    double third_part = b * pow(sin(pow(x, 2)),3);

    // Проверка через switch
    // switch (function) {
    //     case 1:
    //         first_part = -3.1415926 * 2 * x;
    //         break;
    //     case 2:
    //         first_part = -3.1415926 * pow(x, 2);
    //         break;
    //     case 3:
    //         first_part = -3.1415926 * (x / 3);
    //         break;
    //     default:
    //         printf("Incorrect function choice\n");
    //         return 0;
    // }

    // Проверка через if
    if (function == 1) { // Выбор функции(1 = 2x, 2 = x^2, 3 = x / 3)
        first_part = -3.1415926 * 2 * x;
    } else if (function == 2) {
        first_part = -3.1415926 * pow(x, 2);
    //} else if (function == 3) {
        first_part = -3.1415926 * (x / 3);
    } else {
        return 0;
    }

    result = first_part + second_part + third_part; // Результат
    printf("Result: %f", result);

}





