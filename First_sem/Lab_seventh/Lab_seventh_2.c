#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("How many students do you want to add: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) { // Цикл для ввода данных о новых стундентах
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

void delete(const char *filename, const char *temp_filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file \n");
        return;
    }

    FILE *temp_file = fopen(temp_filename, "w"); // Файл для записи отличников
    if (temp_file == NULL) {
        printf("Error creating data file \n");
        fclose(file);
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

    char buffer[256];
    int n = 0;
    int line = 1;
    printf("Enter number of student who must me deleted: ");
    scanf("%d", &n);

    rewind(file);
    while (fgets(buffer, sizeof(buffer), file)) {
        if (line != n) {
            fputs(buffer, temp_file);
        }
        line++;
    }
    fclose(file);
    fclose(temp_file);

    remove(filename);
    rename(temp_filename, filename);

    printf("\nStudents successfully deleted\n");

}

void edit(const char *filename, const char *temp_filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file \n");
        return;
    }

    FILE *temp_file = fopen(temp_filename, "w"); // Файл для записи отличников
    if (temp_file == NULL) {
        printf("Error creating data file \n");
        fclose(file);
        return;
    }

    struct Student s;
    int line = 1;

    printf("\n================ LIST OF STUDENTS ================\n");
    printf("%-15s | %-6s | Phys | Math | IT | Avg\n", "Lastname", "Group");
    printf("--------------------------------------------------\n");

    while (fscanf(file, " %49[^;];%d;%d;%d;%d;%f", s.lastname, &s.group, &s.mark_physic, &s.mark_math, &s.mark_IT, &s.avg_mark) == 6) {
        printf("%-15s | %-6d | %-4d | %-4d | %-2d | %.2f\n", s.lastname, s.group, s.mark_physic, s.mark_math, s.mark_IT, s.avg_mark);
        line++;
    }
    printf("==================================================\n");

    if (line == 1) {
        printf("File is empty");
        fclose(file);
        fclose(temp_file);
        return;
    }

    int n = 0;
    printf("Enter the number of the student you wish to edit: ");
    scanf("%d", &n);

    if (n < 1 || n >= line) {
        printf("Invalid student number \n");
        fclose(file);
        fclose(temp_file);
    }

    rewind(file);
    line = 1;

    while (fscanf(file, " %49[^;];%d;%d;%d;%d;%f", s.lastname, &s.group, &s.mark_physic, &s.mark_math, &s.mark_IT, &s.avg_mark) == 6) {
        if (line == n) {
            int field;
            printf("\nWhat do you want to edit?\n");
            printf("1. Lastname\n");
            printf("2. Group\n");
            printf("3. Physic mark\n");
            printf("4. Math mark\n");
            printf("5. IT mark\n");
            printf("6. Edit everything\n");
            printf("Choice: ");
            scanf("%d", &field);

            switch (field) {
                case 1:
                    printf("Enter new lastname: ");
                    scanf("%49s", s.lastname);
                    break;
                case 2:
                    printf("Enter new group: ");
                    scanf("%d", &s.group);
                    break;
                case 3:
                    printf("Enter new physic mark: ");
                    scanf("%d", &s.mark_physic);
                    break;
                case 4:
                    printf("Enter new math mark: ");
                    scanf("%d", &s.mark_math);
                    break;
                case 5:
                    printf("Enter new IT mark: ");
                    scanf("%d", &s.mark_IT);
                    break;
                case 6:
                    s = input_student();
                    break;
                default:
                    printf("Invalid field! Keeping old data.\n");
            }

            s.avg_mark = (s.mark_physic + s.mark_IT + s.mark_math) / 3;
        }

        fprintf(temp_file, "%s;%d;%d;%d;%d;%.2f\n", s.lastname, s.group, s.mark_physic, s.mark_math, s.mark_IT, s.avg_mark);
        line++;
    }

    fclose(file);
    fclose(temp_file);

    remove(filename);
    rename(temp_filename, filename);

    printf("\nStudents successfully edited\n");

}

void sort(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file \n");
        return;
    }

    struct Student arr[100];
    int count = 0;

    while (count < 100 && fscanf(file, " %49[^;];%d;%d;%d;%d;%f", arr[count].lastname, &arr[count].group, &arr[count].mark_physic, &arr[count].mark_math, &arr[count].mark_IT, &arr[count].avg_mark) == 6) {
        count++;
    }
    fclose(file);

    if (count < 2) {
        printf("Not enough students to sort \n");
        return;
    }

    int choice;
    printf("\n--- Sort by ---\n");
    printf("1. Lastname (A -> Z)\n");
    printf("2. Average mark (Ascending: 1 -> 10)\n");
    printf("3. Average mark (Descending: 10 -> 1)\n");
    printf("Choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swap = 0;

            if (choice == 1 && strcmp(arr[j].lastname, arr[j + 1].lastname) > 0) {
                swap = 1;
            }
            else if (choice == 2 && arr[j].avg_mark > arr[j + 1].avg_mark) {
                swap = 1;
            }
            else if (choice == 3 && arr[j].avg_mark < arr[j + 1].avg_mark) {
                swap = 1;
            }

            if (swap == 1) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    file = fopen(filename, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%d;%d;%d;%d;%.2f\n", arr[i].lastname, arr[i].group, arr[i].mark_physic, arr[i].mark_math, arr[i].mark_IT, arr[i].avg_mark);
    }
    fclose(file);

    printf("Sorted successfully \n");
}

int main() {
    const char *data_file = "students.txt"; // Задаем имя файла для переменной
    const char *result_file = "result.txt";
    const char *temp_file = "temp.txt";
    int choice;

    do { // Выполняем цикл до момента, пока не будет введен "0"
        printf("\n========== MENU ==========\n");
        printf("1. Create file\n");
        printf("2. View all students\n");
        printf("3. Append students\n");
        printf("4. Excellent students in group\n");
        printf("5. Delete student from the file\n");
        printf("6. Edit info about student\n");
        printf("7. Sorted students\n");
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
            case 5:
                delete(data_file, temp_file);
                break;
            case 6:
                edit(data_file, temp_file);
                break;
            case 7:
                sort(data_file);
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
