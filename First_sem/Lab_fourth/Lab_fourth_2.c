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

    double last_positive_elem = arr[size - 1];
    int index = size;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            break;
        } else {
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
        if (arr[i] < 0) {
            if (arr[i] > first_positive_elem) {
                first_positive_elem = arr[i];
                index = i;
                break;
            }
        } else if (arr[i] > 0) {
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
            printf("Your array contain similar positive elements or two elements equal zero \n");
        } else if (array[first_positive_element(array,n)] < 0 && array[last_positive_element(array,n)] < 0) {
            printf("Your array contain only negative numbers \n");
        } else {
            for (int i = first_positive_element(array, n) + 1; i < last_positive_element(array, n) - 1; i++) {
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