#include <stdio.h>

#define N 1000   // максимальный размер массива

// Заполнение массива значениями
double* full_elements(double *ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        // Пример: заполнение по формуле, можно заменить на ввод с клавиатуры
        ptr_array[i] = (i + 1) * 1.5;
    }
    return ptr_array;
}

// Печать элементов массива
int put_elements(double *ptr_array, int n) {
    printf("Элементы массива:\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %.2f\n", i, ptr_array[i]);
    }
    return 0;
}

// Обработка элементов массива
double* calc_elements(double *ptr_array, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += ptr_array[i];
    }
    double avg = (n > 0) ? sum / n : 0.0;

    printf("\nОбработка массива:\n");
    printf("Сумма элементов = %.2f\n", sum);
    printf("Среднее значение = %.2f\n", avg);

    // Пример обработки: вычитание среднего из каждого элемента
    for (int i = 0; i < n; i++) {
        ptr_array[i] -= avg;
    }
    return ptr_array;
}

int main(void) {
    double array[N];
    int size;

    printf("Введите размер массива > ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > N) {
        printf("Некорректный размер массива!\n");
        return 1;
    }

    // Заполнение массива
    full_elements(array, size);

    // Печать исходного массива
    put_elements(array, size);

    // Обработка массива
    calc_elements(array, size);

    // Печать массива после обработки
    printf("\nМассив после обработки:\n");
    put_elements(array, size);

    return 0;
}
