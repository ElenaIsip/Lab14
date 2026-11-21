#include <stdio.h>

#define N 1000   // максимальный размер массива



// Заполнение массива значениями
double* full_elements(double *ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = (i + 1) * 1.5;   // пример заполнения
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
    for (int i = 0; i < n; i++) sum += ptr_array[i];
    double avg = (n > 0) ? sum / n : 0.0;

    printf("\nОбработка массива:\n");
    printf("Сумма элементов = %.2f\n", sum);
    printf("Среднее значение = %.2f\n", avg);

    for (int i = 0; i < n; i++) ptr_array[i] -= avg;
    return ptr_array;
}

/* ---------- Новые функции из Задания 2 ---------- */

// Сумма элементов массива с индекса begin по end включительно
double sum_elements(double *ptr_array, int begin, int end) {
    // Защита от некорректных границ
    if (begin < 0) begin = 0;
    if (end < begin) return 0.0;

    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}


int find_element(double *ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
   
        if (fabs(ptr_array[i] - element) < 1e-9) {
            return i;
        }
    }
    return -1;
}



int main(void) {
    double array[N];
    int size;

    printf("Введите размер массива > ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > N) {
        printf("Некорректный размер массива!\n");
        return 1;
    }

    // Заполнение и печать
    full_elements(array, size);
    put_elements(array, size);

   
    calc_elements(array, size);
    put_elements(array, size);

    int begin, end;
    printf("\nВведите begin и end для суммы (0 <= begin <= end < %d) > ", size);
    if (scanf("%d %d", &begin, &end) != 2) {
        printf("Ошибка ввода границ!\n");
        return 1;
    }
    if (begin < 0 || end >= size || begin > end) {
        printf("Некорректные границы!\n");
    } else {
        double s = sum_elements(array, begin, end);
        printf("Сумма элементов с %d по %d = %.2f\n", begin, end, s);
    }

  
    double value;
    printf("\nВведите значение для поиска > ");
    if (scanf("%lf", &value) != 1) {
        printf("Ошибка ввода значения!\n");
        return 1;
    }
    int idx = find_element(array, size, value);
    if (idx == -1) {
        printf("Элемент %.2f не найден.\n", value);
    } else {
        printf("Элемент %.2f найден по индексу %d (array[%d] = %.2f).\n",
               value, idx, idx, array[idx]);
    }

    return 0;
}
