// Бондаренко Степан 621704 | Лаба 3 | 3 Вариант | 20.09.2026

#include <stdio.h>
#include <math.h>

void clear_input(void) { // Функция для очистки памяти программы
    int c;
    while ((c = getchar()) != '\n') {

    }
}

int main(void) {

    int again = 0;
    do { // Цикл до момента, пока again != 1
        double a, b, h;
        int n;
        while (1) { // Бесконечный цикл, до момента, пока не будет введено корректное число
            printf("Enter a, b, h, n: ");
            int res = scanf("%lf %lf %lf %d", &a, &b, &h, &n);
            clear_input();

            if (res != 4) {
                printf("Incorrect numbers.\n");
            } else if (a > b) {
                printf("a must be <= b.\n");
            } else if (h <= 0) {
                printf("h must be > 0.\n");
            } else if (n < 0) {
                printf("n must be >= 0.\n");
            } else {
                break;
            }
        }

        printf("-------------------------------------------------------------------------\n");
        printf("|    x     |     Y(x)     |     S(x)     |         |Y(x) - S(x)|       |\n");
        printf("-------------------------------------------------------------------------\n");

        for (int k = 0; a + k * h <= b + h / 2; k++) {
            double x = a + k * h;

            double first_number_p1 = exp(x * cos(M_PI / 4));
            double first_number_p2 = cos(x * sin(M_PI / 4));
            double first_number = first_number_p1 * first_number_p2; // Нахождение Y(x)

            double sum_second_number = 0;
            double term = 1;
            for (int i = 0; i <= n; i++) { // Нахождение S(x)
                if (i > 0) {
                    term *= x / i;
                }
                sum_second_number += cos(i * M_PI / 4) * term;
            }

            double module = fabs(first_number - sum_second_number);
            printf("| %-8.4f | %-12.6f | %-12.6f | %-27.6e |\n", x, first_number, sum_second_number, module);
            printf("-------------------------------------------------------------------------\n");

        }

        while (1) {
            printf("Do you want to continue?(Enter 1 - if you want finish; 0 - if you want to continue): ");
            int res = scanf("%d", &again);
            clear_input();
            if (res == 1 && (again == 0 || again == 1)) {
                break;
            }
            printf("Enter 0 or 1.\n");
        }
    } while (again != 1);

    return 0;
}