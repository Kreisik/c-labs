#include "stdio.h"
#include "stdlib.h"

void clear_input(void) { // Функция для очистки памяти программы
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

int findMaxInMatrixRow(int **matrix, int m, int n) { // Функция для нахождения минимального числа в строке
    int maxVal = matrix[m][0];

    for (int j = 1; j < n; j++) {
        if (matrix[m][j] > maxVal) {
            maxVal = matrix[m][j];
        }
    }

    return maxVal;
}

int main() {
    int again = 0;

    do {
        int **table; // Указатель для двумерного массива
        int m = 0;
        int n = 0;
        int x = 0;

        while (1) {
            // Бесконечный цикл, до момента, пока не будет введено корректное число
            printf("Enter m, n: ");
            int res = scanf("%d %d", &m, &n);
            if (res == EOF) {
                return 1;
            }
            clear_input();

            if (res != 2) { // Проверки на коррекстность ввода
                printf("Incorrect numbers.\n");
            } else if (n <= 0) {
                printf("n must be > 0.\n");
            } else if (m < 0) {
                printf("m must be >= 0.\n");
            } else {
                break;
            }
        }

        table = malloc(m * sizeof(int*)); // Выделение памяти для строк
        for (int i = 0; i < m; i++) {
            table[i] = malloc(n * sizeof(int)); // Выделение памяти для столбцов
        }

        printf("\nEnter matrix elements:\n");
        for (int i = 0; i < m; i++) { //Ввод элементов массива
            for (int j = 0; j < n; j++) {
                printf("table[%d][%d]: ", i, j);
                scanf("%d", &x);
                table[i][j] = x;
            }
        }

        for (int i = 0; i < m - 1; i++) { // Сортировка массива
            int min_idx = i;
            for (int j = i + 1; j < m; j++) {
                if (findMaxInMatrixRow(table, j, n) < findMaxInMatrixRow(table, min_idx, n)) { // Условие если элемент i + 1 меньше элемента i
                    min_idx = j; // Если это так то индекс элемента минимального равен j
                }
            }

            if (min_idx != i) { // Если поменялось min_idx, то меняем местами строчки
                int *temp = table[i];
                table[i] = table[min_idx];
                table[min_idx] = temp;
            }
        }

        printf("\nSorted matrix:\n"); // Вывод массива
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%4d", table[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < m; i++) { // Очистка памяти
            free(table[i]);
        }
        free(table);

    } while (again != 0);

}