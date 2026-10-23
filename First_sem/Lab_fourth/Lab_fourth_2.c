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

    double last_positive_elem = arr[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > last_positive_elem) {
            last_positive_elem = arr[i];
            index = i;
        }
    }

    return index;

}

int first_positive_element(const double arr[], int size) {

    double first_positive_elem = arr[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > first_positive_elem) {
            first_positive_elem = arr[i];
            index = i;
            break;
        }
    }
    return index;

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

        double sum_of_elements = 0;
        if (first_positive_element(array,n) == last_positive_element(array, n)) {
            printf("Sum of elements between first and last positive elements: %f", array[first_positive_element(array, n)]);
        } else if (array[first_positive_element(array,n)] < 0 && array[last_positive_element(array,n)] < 0) {
            printf("Your array contain only negative numbers");
        } else {
            for (int i = first_positive_element(array, n); i < last_positive_element(array, n); i++) {
                sum_of_elements += array[i];
            }
            printf("Sum of elements between first and last positive elements: %f", sum_of_elements);
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