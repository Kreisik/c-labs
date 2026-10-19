#include "stdio.h"
#include <string.h>

int main() {

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
}