#include "stdio.h"
#include "stdlib.h"

void clear_input(void) { // Функция для очистки памяти программы
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

int main() {

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
        table[i] = malloc(n * sizeof(int)); // Выделение памяит для столбцов
    }

    printf("\nEnter matrix elements:\n");
    for (int i = 0; i < m; i++) { //Ввод элементов массива
        for (int j = 0; j < n; j++) {
            printf("table[%d][%d]: ", i, j);
            scanf("%d", &x);
            table[i][j] = x;
        }
    }

    int count = 0;

    for (int j = 0; j < n; j++) { // Проверка на наличие нуля в столбце
        int flag_zero = 0;

        for (int i = 0; i < m; i++) {
            if (table[i][j] == 0) {
                flag_zero = 1;
                break;
            }
        }

        if (flag_zero == 1) {
            count++;
        }
    }

    printf("Count columns with zero: %d", count);
    for (int i = 0; i < m; i++) { // Очистка памяти
        free(table[i]);
    }
    free(table);

    return 0;
}