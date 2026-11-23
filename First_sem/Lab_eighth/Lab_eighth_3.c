#include <stdio.h>

void clear_input(void) { // Функция для очистки памяти программы
    int c;
    while ((c = getchar()) != '\n') {

    }
}

int findGST2(int m, int n) {

    if (m % n == 0) {
        return n;
    }

    return findGST2(n, m % n);

}

int findGST(int m, int n) {

    if (m < n) {
        int res = m;
        m = n;
        n = res;
    }

    if (m % n == 0) {
        return n;
    } else {
        while (m % n != 0) {
            int res = (m / n) * n;
            m = m - res;
            if (m < n) {
                int res = m;
                m = n;
                n = res;
            }
        }
        return n;
    }

}

int main() {
    int again = 0;

    do {
        int m = 0, n = 0;

        while (1) {
            printf("Enter m, n: ");
            int res = scanf("%d %d", &m, &n);

            int next_char = getchar();
            if (res == 2 && m > 0 && n > 0 && next_char == '\n') {
                break;
            }

            if (next_char != '\n') {
                clear_input();
            }
            printf("Invalid input! Please enter two positive integers \n");
        }

        int result = findGST(m, n);
        printf("Result: %d", result);
        int result2 = findGST2(m, n);
        printf("Result: %d", result2);
        if (result == result2) {
            printf("Results are similar");
        }

        while (1) {
            printf("Do you want to continue? (Enter 0 - if you want finish; 1 - if you want to continue): ");
            int res = scanf("%d", &again);
            clear_input();

            if (res == 1 && (again == 0 || again == 1)) {
                break;
            }
            printf("Enter 0 or 1.\n");
        }
    } while (again != 0);
}