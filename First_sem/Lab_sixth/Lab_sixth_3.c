#include <stdio.h>
#include <string.h>

void clear_input(void) { // Функция для очистки памяти программы
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

int main() {
    int again = 0;

    do {
        char str_1[256]; // Создание и ввод первой строки
        printf("Enter string_1: ");
        scanf("%255s", str_1);

        char str_2[256]; // Создание и ввод второй строки
        printf("Enter string_2: ");
        scanf("%255s", str_2);

        strcat(str_1, str_2); // Добавление второй строки к первой
        strcat(str_1, str_2); // // Добавление второй строки к первой

        printf("Result: %s\n", str_1);

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