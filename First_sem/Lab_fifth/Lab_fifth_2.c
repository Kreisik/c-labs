#include "stdio.h"
#include "stdlib.h"

void clear_input(void) { // Функция для очистки памяти программы
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

int main() {
    int again = 0;

    do {
        int **table; // Указатель для двумерного массива
        int *vector;
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
        vector = malloc(m * sizeof(int)); // Выделение памяти под массив вектора

        printf("\nEnter matrix elements:\n");
        for (int i = 0; i < m; i++) { //Ввод элементов массива
            for (int j = 0; j < n; j++) {
                printf("table[%d][%d]: ", i, j);
                scanf("%d", &x);
                table[i][j] = x;
            }
        }

        int center = n / 2;
        int count = 0;
        for (int i = 0; i < m; i++) {
            int last_number = n - 1;
            for (int j = 0; j < center; j++) {
                if (table[i][j] == table[i][last_number]) {
                    count++;
                }
                last_number--;
            }
            if (count == center) {
                vector[i] = 1;
            } else {
                vector[i] = 0;
            }
            count = 0;
        }

        printf("Vector B: ");
        for (int i = 0; i < m; i++) {
            printf("%d ", vector[i]);
        }
        free(vector);

        for (int i = 0; i < m; i++) { // Очистка памяти
            free(table[i]);
        }
        free(table);

        while (1) {
            printf("Do you want to continue? (Enter 1 - if you want finish; 0 - if you want to continue): ");
            int res = scanf("%d", &again);
            clear_input();

            if (res == 1 && (again == 0 || again == 1)) {
                break;
            }
            printf("Enter 0 or 1.\n");
        }

    } while (again != 0);

}