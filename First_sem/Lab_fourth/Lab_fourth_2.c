// Бондаренко Степан 621704 | Лаба 4 | 3 Вариант | 30.09.2026

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_input(void) {
    // Функция для очистки буфера ввода
    int c;
    while ((c = getchar()) != '\n') { }
}

int last_positive_element(const double arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            return i;
        }
    }
    return -1;
}

int first_positive_element(const double arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int again = 0;
    do {
        int n;

        while (1) {
            printf("Enter length of array: ");
            int res = scanf("%d", &n);
            clear_input();

            if (res != 1 || n <= 0) {
                printf("Incorrect number! Length must be > 0.\n");
            } else {
                break;
            }

        }
        double array[n];


        int choose;
        printf("Choose type of fill array(1 - by yourself; 2 - auto): ");
        scanf("%d", &choose);
        if (choose == 1) {
            printf("Enter elements of array: ");
            for (int i = 0; i < n; i++) {
                scanf("%lf", &array[i]);
            }
        } else if (choose == 2) {
            srand(time(NULL));

            int A = 1;
            int B = 100;

            for (int i = 0; i < n; i++) {
                array[i] = rand() % (B - A + 1) + A;
            }
        } else {
            printf("Incorrect answer");
            return 0;
        }

        int first_idx = first_positive_element(array, n);
        int last_idx = last_positive_element(array, n);

        double sum_of_elements = 0;
        if (first_idx == -1 || last_idx == -1) {
            printf("Your array does not contain positive elements.\n");
        } else if (first_idx == last_idx) {
            printf("Your array contains only one positive element. No elements between.\n");
        } else if (first_idx + 1 == last_idx) {
            printf("First and last positive elements are adjacent. Sum is 0.\n");
        } else {
            for (int i = first_idx + 1; i < last_idx; i++) {
                sum_of_elements += array[i];
            }
            printf("Sum of elements between first and last positive elements: %f \n", sum_of_elements);
        }


        while (1) {
            printf("Do you want to continue? (Enter 1 - if you want finish; 0 - if you want to continue): ");
            int res = scanf("%d", &again);
            clear_input();

            if (res == 1 && (again == 0 || again == 1)) {
                break;
            }
            printf("Enter 0 or 1.\n");
        }

    } while (again != 1);
}