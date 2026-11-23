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

    s.avg_mark = (s.mark_IT + s.mark_math + s.mark_physic) / 3.0f;
    return s;
}

void create_file(const char *filename) { // Функция для создания файла
    FILE *file = fopen(filename, "w");
    if (file == NULL) { // Проверка на открытие файла
        printf("Error with file open\n");
        return;
    }

    int count;
    printf("Enter count of students: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) { // Цикл для ввода данных о студентах
        printf("\n--- Student №%d ---", i + 1);
        struct Student s = input_student();

        fprintf(file, "%s;%d;%d;%d;%d;%.2f\n", s.lastname, s.group, s.mark_physic, s.mark_math, s.mark_IT, s.avg_mark);
    }

    fclose(file);
    printf("\nFile successfully saved!\n");
}

void view_file(const char *filename) { // Функция для просмотра содержимого файла
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file \n");
        return;
    }

    struct Student s;
    printf("\n================ LIST OF STUDENTS ================\n");
    printf("%-15s | %-6s | Phys | Math | IT | Avg\n", "Lastname", "Group");
    printf("--------------------------------------------------\n");

    while (fscanf(file, " %49[^;];%d;%d;%d;%d;%f", s.lastname, &s.group, &s.mark_physic, &s.mark_math, &s.mark_IT, &s.avg_mark) == 6) {
        printf("%-15s | %-6d | %-4d | %-4d | %-2d | %.2f\n", s.lastname, s.group, s.mark_physic, s.mark_math, s.mark_IT, s.avg_mark);
    }
    printf("==================================================\n");

    fclose(file);
}

void append_file(const char *filename) { // Функция для добавления новых студентов
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file \n");
        return;
    }

    int count;
    printf("How many students do you want to add?");
    scanf("%d", &count);

    for (int i = 0; i < 0; i++) { // Цикл для ввода данных о новых стундентах
        printf("--- New Student #%d ---", i + 1);
        struct Student s = input_student();

        fprintf(file, "%s;%d;%d;%d;%d;%.2f\n", s.lastname, s.group, s.mark_physic, s.mark_math, s.mark_IT, s.avg_mark);
    }
    fclose(file);
    printf("\nStudents successfully added\n");
}

void find_best_student(const char *filename, const char *result_filename) { // Функция для нахождения отличников
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening data file! Create it first.\n");
        return;
    }

    FILE *res_file = fopen(result_filename, "w"); // Файл для записи отличников
    if (res_file == NULL) {
        printf("Error creating data file \n");
        fclose(file);
        return;
    }

    int target_group;
    printf("\nEnter group number: \n");
    scanf("%d", &target_group);

    struct Student s;
    int found = 0;

    printf("\n--- Excellent students in group %d ---\n", target_group);
    fprintf(res_file, "Excellent students in group %d:\n", target_group);

    while (fscanf(file, " %49[^;];%d;%d;%d;%d;%f", s.lastname, &s.group, &s.mark_physic, &s.mark_math, &s.mark_IT, &s.avg_mark) == 6) {
        if (s.group == target_group && s.mark_physic >= 9 && s.mark_IT >= 9 && s.mark_math >= 9) {
            printf("%s | Phys: %d, Math: %d, IT: %d | Avg: %.2f\n", s.lastname, s.mark_physic, s.mark_math, s.mark_IT, s.avg_mark);

            fprintf(res_file, "%s;%d;%d;%d;%d;%.2f\n", s.lastname, s.group, s.mark_physic, s.mark_math, s.mark_IT, s.avg_mark);
            found = 1;
        }
    }

    if (!found) {
        printf("No excellent students in this group \n");
    } else {
        printf("\n Result successfully saved \n");
    }

    fclose(file);
    fclose(res_file);
}

int main() {
    const char *data_file = "students.txt"; // Задаем имя файла для переменной
    const char *result_file = "result.txt";
    int choice;

    do { // Выполняем цикл до момента, пока не будет введен "0"
        printf("\n========== MENU ==========\n");
        printf("1. Create file (overwrite)\n");
        printf("2. View all students\n");
        printf("3. Append students\n");
        printf("4. Solve task (Excellent students in group)\n");
        printf("0. Exit\n");
        printf("==========================\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) { // Выбор то или иной функции
            case 1:
                create_file(data_file);
                break;;
            case 2:
                view_file(data_file);
                break;
            case 3:
                append_file(data_file);
                break;
            case 4:
                find_best_student(data_file, result_file);
                break;
            case 0:
                printf("Exiting program... \n");
                break;
            default:
                printf("Invalid option \n");
        }
    } while (choice != 0);

    return 0;
}
