#include <stdio.h>
#include <stdlib.h>

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

    int n, k;
    printf("Enter length of array: ");
    if (scanf("%d", &n) != 1 || n <= 0) { // Проверка на ввод корректного n
        printf("Incorrect number! \n");
        return 1;
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

    printf("Enter k: ");
    if (scanf("%d", &k) != 1 || k < 0) { // Проверка на ввод k
        printf("Incorrect number \n");
        free(array);
        return 1;
    }

    printf("Before: ");
    printArr(array, n);

    leftreverse(array, n, k);

    printf("After: ");
    printArr(array, n);

    free(array);
    return 0;
}
