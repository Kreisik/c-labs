#include <stdio.h>

// double GetMax(const double arr[], int size) { // Функция для нахождения минимального значения
//
//     double maxVal = arr[0];
//     for (int i = 1; i < size; i++) {
//         if (arr[i] > maxVal) {
//             maxVal = arr[i];
//         }
//     }
//
//     return maxVal;
// }
//
// double GetMin(const double arr[], int size) { // Функция для нахождения минимального значения
//
//     double minVal = arr[0];
//     for (int i = 1; i < size; i++) {
//         if (arr[i] < minVal) {
//             minVal = arr[i];
//         }
//     }
//
//     return minVal;
// }

double last_positive_element(const double arr[], int size) {

    int last_index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            last_index = i;
        }
    }
    return last_index;

}

// double last_negative_element(const double arr[], int size) {
//
//     double last_negative_elem = arr[0];
//     int index = 0;
//     for (int i = 1; i < size; i++) {
//         if (arr[i] < last_negative_elem) {
//             last_negative_elem = arr[i];
//             index = i;
//         }
//     }
//
//     return index;
//
// }
//
// double zero_last_element(const double arr[], int size) {
//
//     int index = 0;
//     for (int i = 1; i < size; i++) {
//         if (arr[i] == 0) {
//             index = i;
//         }
//     }
//
//     return index;
//
// }

int main() {

    int n;
    printf("Enter length of array: ");
    if (scanf("%d", &n) != 1 || n <= 0) { // Проверка на ввод корректного n
        printf("Incorrect number! \n");
        return 1;
    }

    double array[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {

        scanf("%lf", &array[i]);

    }

    //Нахождение ср. арифм. положительных чисел
    // double sum_of_positive_numbers = 0;
    // double number_of_positive_numbers = 0;
    // for (int i = 0; i < n; i ++) {
    //
    //     if (array[i] > 0) {
    //
    //         sum_of_positive_numbers += array[i];
    //         number_of_positive_numbers++;
    //
    //     }
    //
    // }
    // double answer_of_arithmetic_mean_positive = sum_of_positive_numbers / number_of_positive_numbers;
    // printf("Arithmetic mean of the positive elements: %f \n", answer_of_arithmetic_mean_positive);
    //
    // //Произведение элементов, расположенных после наибольшего элемента
    // double max = GetMax(array, n);
    // double sum_of_multiplication_max = 1;
    // int position = 0;
    //
    // for (int i = 0; i < n; i++) {
    //     if (array[i] == max) {
    //         position = i + 1;
    //         break;
    //     }
    // }
    //
    // while (position < n) {
    //
    //     sum_of_multiplication_max *= array[position];
    //     position++;
    //
    // }
    // printf("Result of multiplication after max value: %f \n", sum_of_multiplication_max);

    //Сумма элементов массива, расположенных до последнего положительного элемента
    double last_positive_element_result = 0;
    if (last_positive_element(array, n) <= 0) {
        printf("Your array doesn`t contain positive numbers");
        return 0;
    }
    for (int i = 0; i < last_positive_element(array, n); i++) {
        last_positive_element_result += array[i];
    }
    printf("The sum of the array elements located before the last positive element: %f \n", last_positive_element_result);

    //Сумма элементов, расположенных до наименьшего элемента
    // double sum_of_elements_before_min = 0;
    // for (int i = 0; i < n; i++) {
    //     while (array[i] != GetMin(array, n)) {
    //         sum_of_elements_before_min += array[i];
    //         i++;
    //     }
    // }
    // printf("The sum of the elements, located before the last positive element: %f \n", sum_of_elements_before_min);

    // // Ср. арифм. отрицательных элементов массива
    // double sum_of_negative_numbers = 0;
    // double number_of_negative_numbers = 0;
    // for (int i = 0; i < n; i ++) {
    //
    //     if (array[i] < 0) {
    //
    //         sum_of_negative_numbers += array[i];
    //         number_of_negative_numbers++;
    //
    //     }
    //
    // }
    // double answer_of_arithmetic_mean_negative = sum_of_negative_numbers / number_of_negative_numbers;
    // printf("Arithmetic mean of the positive elements: %f \n", answer_of_arithmetic_mean_negative);
    //
    // //Сумма дробных частей элементов массива
    // double sum_of_frac_parts = 0;
    // double int_part, frac_part;
    // for (int i = 0; i < n; i++) {
    //     if (fmod(array[i], 1) != 0) {
    //         frac_part = modf(array[i], &int_part);
    //         sum_of_frac_parts += frac_part;
    //     }
    // }
    // printf("Sum of frac parts: %f, \n", sum_of_frac_parts);
    //
    // //Сумма целых частей элементов массива, расположенных после последнего отрицательного элемента
    // double sum_of_main_part_after_last_negative_element = 0;
    // for (int i = last_negative_element(array, n); i < n; i++) {
    //     sum_of_main_part_after_last_negative_element += array[i];
    // }
    // printf("The sum of the integer parts of the array elements located after the last negative element: %f, \n", sum_of_main_part_after_last_negative_element);
    //
    // //Сумма элементов массива, расположенных после последнего элемента, равного нулю
    // double sum_after_last_zero = 0;
    // for (int i = zero_last_element(array, n); i < n; i++) {
    //     sum_after_last_zero += array[i];
    // }
    // printf("The sum of the array elements located after the last element equal to zero: %f, \n", sum_after_last_zero);
    //
    // //Массив модулей
    // double module_array[n];
    // for (int i = 0; i < n; i++) {
    //     module_array[i] = fabs(array[i]);
    // }
    //
    // //Сумма модулей элементов, расположенных после минимального по модулю элемента
    // double sum_of_modules_after_min_element = 0;
    // for (int i = 0; i < n; i++) {
    //     if (module_array[i] == GetMin(module_array, n)) {
    //         sum_of_modules_after_min_element += module_array[i];
    //     }
    // }
    // printf("The sum of the absolute values of the array elements located after the element with the minimum absolute value: %f, \n", sum_of_modules_after_min_element);


}