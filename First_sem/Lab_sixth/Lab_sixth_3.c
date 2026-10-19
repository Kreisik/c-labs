#include <stdio.h>
#include <string.h>

int main() {

    char str_1[256]; // Создание и ввод первой строки
    printf("Enter string_1: ");
    scanf("%255s", str_1);

    char str_2[256]; // Создание и ввод второй строки
    printf("Enter string_2: ");
    scanf("%255s", str_2);

    strcat(str_1, str_2); // Добавление второй строки к первой
    strcat(str_1, str_2); // // Добавление второй строки к первой

    printf("Result: %s\n", str_1);
}