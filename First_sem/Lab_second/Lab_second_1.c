// Бондаренко Степан 621704 | Лаба 2 | 3 Вариант | 14.09.2026

#include <math.h>
#include <stdio.h>

int main() {
    double result;
    double x, b, z;
    printf("Enter b, z: ");
    scanf("%lf %lf", &b, &z);
    if (b == 0) {
        printf("Divide to zero incorrect");
        return 0;
    }
    if (z >= 1) { // При условии z >= 1

        x = sqrt(pow(z * b, 3));
        printf("Result if z >= 1: ");

    } else { // при условии z < 1

        x = z / b;
        printf("Result if z < 1: ");

    }

    double first_part = -3.1415926;
    double second_part = pow(cos(pow(x, 3)), 2);
    double third_part = pow(sin(pow(x, 2)), 3);

    result = first_part + second_part + third_part; // Результат
    printf("%f", result);

}