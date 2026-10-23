// Бондаренко Степан 621704 | Лаба 4 | 3 Вариант | 30.09.2026

#include <stdio.h>
#include <stdlib.h>

void clear_input(void) {
    // Функция для очистки буфера ввода
    int c;
    while ((c = getchar()) != '\n') { }
}

void reverse(int* arr, int left, int right) { // Функция для сдвига массива
    while (left < right) {
        int tmp = arr[left]; // Записываем чему равно arr[left]
        arr[left] = arr[right]; // Меняем arr[left] на arr[right]
        arr[right] = tmp;
        left++;
        right--;
    }
}

void leftreverse(int* arr, int n, int k) { // Функция для вызова reverse 3 раза
    k = k % n;
    if (k == 0) {
        return;
    }
    reverse(arr, 0, k - 1); // Первый раз сдвигаем от первого элемента до k
    reverse(arr, k, n - 1); // Второй сдвиг от k-ого элемента до конца массива
    reverse(arr, 0, n  - 1); // Третий сдвиг уже всего массива
}

void printArr(const int* arr, int n) { // Функция вывода массива
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int again = 0;

    do {
        int n, k;

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

        int* array = (int*)malloc(n * sizeof(int)); // Создание динамического массива
        if (array == NULL) {
            printf("Error with memory! \n");
            return 1;
        }

        for (int i = 0; i < n; i++) { // Заполенение массива
            printf("array[%d] = ", i);
            if (scanf("%d", &array[i]) != 1) {
                printf("Incorrect number! \n");
                free(array);
                return 1;
            }
        }

        while (1) {
            printf("Enter shift of elements: ");
            int res = scanf("%d", &k);
            clear_input();

            if (res != 1 || n <= 0) {
                printf("Incorrect number! Length must be > 0.\n");
            } else {
                break;
            }

        }

        printf("Before: ");
        printArr(array, n);

        leftreverse(array, n, k);

        printf("After: ");
        printArr(array, n);

        free(array);
        return 0;

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
