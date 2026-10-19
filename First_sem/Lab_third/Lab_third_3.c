// Бондаренко Степан 621704 | Лаба 3 | 3 Вариант | 20.09.2026

#include <stdio.h>
#include <math.h>


double first_function(double number) { // Функция нахождения Y(x)

    double first_number_p1 = exp(number * cos(M_PI / 4));
    double first_number_p2 = cos(number * sin(M_PI / 4));
    return first_number_p1 * first_number_p2;

}

double second_function(double number, int count) { // Функция нахождение S(x)

    double sum_second_number = 1;
    double term = 1;
    for (int i = 1; i <= count; i++) { // Нахождение S(x)
            term *= number / i;
            sum_second_number += cos(i * M_PI / 4) * term;
    }

    return sum_second_number;
}

void clear_input(void) { // Функция для очистки памяти программы
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

int main(void) {

    int again = 0;
    do { // Цикл до момента, пока again != 1
        double a, b, h, e;
        while (1) { // Бесконечный цикл, до момента, пока не будет введено корректное число
            printf("Enter a, b, h, e: ");
            int res = scanf("%lf %lf %lf %lf", &a, &b, &h, &e);
            if (res == EOF) {
                return 1;
            }
            clear_input();

            if (res != 4) { // Проверки на коррекстность ввода
                printf("Incorrect numbers.\n");
            } else if (a > b) {
                printf("a must be <= b.\n");
            } else if (h <= 0) {
                printf("h must be > 0.\n");
            } else if (e < 0) {
                printf("e must be >= 0.\n");
            } else {
                break;
            }
        }

        printf("---------------------------------------------------------------------------------\n");
        printf("|    x     |     Y(x)     |     S(x)     |   |Y(x) - S(x)|    |   Steps     |\n");
        printf("---------------------------------------------------------------------------------\n");

        int count = 1; // Счетчик шагов
        for (int k = 0; a + k * h <= b + h / 2; k++) {
            double x = a + k * h;
            double y = first_function(x);

            int times = 0;
            double sum_second_number = second_function(x, times);
            double module = fabs(sum_second_number - y);

            while (module >= e) { // Цикл выополняется до того момента, пока module >= e
                times++;
                sum_second_number = second_function(x, times);
                module = fabs(sum_second_number - y);
            }

            printf("| %-8.4f | %-12.6f | %-12.6f | %-18.6e | %-11d |\n", x, y, sum_second_number, module, count);
            printf("---------------------------------------------------------------------------------\n");
            count++;
        }

        while (1) { // Бесконечный цикл до момента, пока пользователь не введет 1
            printf("Do you want to continue?(Enter 1 - if you want finish; 0 - if you want to continue): ");
            int res = scanf("%d", &again);
            if (res == EOF) {
                return 0;
            }
            clear_input();
            if (res == 1 && (again == 0 || again == 1)) {
                break;
            }
            printf("Enter 0 or 1.\n");
        }
    } while (again != 1);

    return 0;
}