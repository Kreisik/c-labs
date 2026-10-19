#include <stdio.h>
#include <string.h>

int main() {


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


}