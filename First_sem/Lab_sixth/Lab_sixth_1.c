#include "stdio.h"
#include <string.h>

void clear_input(void) { // Функция для очистки памяти программы
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

int main() {
    int again = 0;

    do {
        char str[256]; // Создание и ввод строки
        printf("Enter string: ");
        scanf("%255s", str);

        int n = strlen(str);
        int center = n / 2;
        int count = 0;
        int last_number = n - 1;
        for (int i = 0; i < center; i++) { // Проверка на палиндромм
            if (str[i] == str[last_number]) {
                count++;
            }
            last_number--;

        }

        if (center == count) {
            printf("The number is a palindrome! \n");
        } else {
            printf("The number is not palindrome! \n");
        }

        if (n >= 3) {
            printf("Last 3 chars: %c %c %c\n", str[n - 3], str[n - 2], str[n - 1]);
        } else {
            printf("The string is too short to print last 3 characters.\n");
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

    } while (again != 0);

}