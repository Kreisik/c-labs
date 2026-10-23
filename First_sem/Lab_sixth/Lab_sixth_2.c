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
        char str[256]; // Создание и ввод строки
        printf("Enter string: ");
        scanf("%255s", str);

        int n = strlen(str); // Нахождение длины строки
        int result = 0;
        int count = 1;
        int target = str[0];
        for (int i = 1; i <= n; i++) {
            if (target == str[i]) { // Проверка на следующие число
                count++;
            } else {
                if (count > result) {
                    result = count;
                }
                count = 1;
                target = str[i];
            }
        }

        printf("Result: %d", result);

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