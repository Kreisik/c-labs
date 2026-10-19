// Бондаренко Степан 621704 | Лаба 3 | 3 Вариант | 20.09.2026

#include <stdio.h>
#include <math.h>

int main(void) {

    int again = 0;
    do {
        double a, b, h;
        printf("Enter a, b, h: ");
        while (scanf("%lf %lf %lf", &a, &b, &h) != 3 || a < 0 || b < 0 || h <= 0) {
            printf("Incorrect numbers. Enter correct numbers: ");

            char c;
            while ((c = getchar()) != '\n' && c != EOF) {
                // Выброс ненужных символов
            }
        }

        // Защита от бесконечного цикла
        if (h == 0) {
            printf("Step h cannot be 0.\n");
            continue;
        }

        double arr[1000];
        int count = 1;
        int size = 0;

        printf("-----------------------------------------\n");
        printf("| i  |     x      |         Y(x)        |\n");
        printf("-----------------------------------------\n");

        while (a <= b && size < 1000) {

            double first_part = a * (sqrt(2) / 2);
            double second_part = 1 - 2 * a * (sqrt(2) / 2) + pow(a, 2);

            if (second_part != 0) {

                double result = first_part / second_part;

                printf("| %-2d | %-10f | %-18f |\n", count, a, result);
                printf("-----------------------------------------\n");

                count++;
                arr[size] = result;
                size++;

                a+=h;

            } else {
                return 0;
            }

        }

        double min = arr[0];
        for (int i = 1; i < size; i++) { // Цикл для минимума функции

            if (arr[i] < min) {

                min = arr[i];

            }

        }

        double max = arr[0];
        for (int i = 1; i < size; i++) { // Цикл для максимума функции

            if (arr[i] > max) {

                max = arr[i];

            }

        }

        printf("Max of function: %f \n", max);
        printf("Min of function: %f \n", min);
        printf("Do you want to continue?(Enter 1 - if you want finish; 0 - if you want to continue): ");
        scanf("%d", &again);
    } while (again != 1);
}