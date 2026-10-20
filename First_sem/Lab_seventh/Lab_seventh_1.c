#include <stdio.h>
#include <stdlib.h>

struct Student { // Создание структуры пользователя
    char lastname[50];
    int group;
    int mark_physic;
    int mark_math;
    int mark_IT;
    float avg_mark;
};

struct Student input_student() { // Функция ввода значения
    struct Student s;
    printf("\nEnter lastname: ");
    scanf("%49s", s.lastname);
    printf("\nEnter group number: ");
    scanf("%d", &s.group);
    printf("\nEnter physic mark: ");
    scanf("%d", &s.mark_physic);
    printf("\nEnter math mark: ");
    scanf("%d", &s.mark_math);
    printf("\nEnter IT mark: ");
    scanf("%d", &s.mark_IT);

    s.avg_mark = (s.mark_IT + s.mark_math + s.mark_physic) / 3;
    return s;
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error with file open!\n");
        return;
    }

    int count;
    printf("Enter count of students? ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("\nStudent №%d:", i + 1);
        struct Student s = input_student();

        fprintf(file, "%s;%d;%d;%d;%d;%.2f\n", s.lastname, s.group, s.mark_physic, s.mark_math, s.mark_IT, s.avg_mark);
    }

    fclose(file);
    printf("\nFile successfully saved!\n");
}

